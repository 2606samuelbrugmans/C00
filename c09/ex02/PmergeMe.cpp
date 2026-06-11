#include "PmergeMe.hpp"


PmergeMe::PmergeMe() { }
PmergeMe::~PmergeMe() { }


// ─────────────────────────────────────────────────────────────────────────────
//  Public interface
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::sortAndDisplay(char **argv, int argc)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        vec.push_back(num);
        deq.push_back(num);
        std::cout << num << " ";
    }

    fordJohnsonSortVector();
    fordJohnsonSortDeque();

    std::cout << "\nAfter: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::sortAndDisplayWithTiming(char **argv, int argc)
{
    std::cout << "Before: ";
    std::set<int> seen;

    for (int i = 1; i < argc; ++i)
    {
        char *endptr = NULL;
        long val = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0')
            throw std::runtime_error("\nError : invalid number '" + std::string(argv[i]) + "'");
        if (val < 0)
            throw std::runtime_error("\nError : number '" + std::string(argv[i]) + "' is negative");
        int num = static_cast<int>(val);
        if (seen.count(num) > 0)
            throw std::runtime_error("\nError : duplicate number '" + std::string(argv[i]) + "' found");
        seen.insert(num);
        vec.push_back(num);
        deq.push_back(num);
        if (i < 5)
            std::cout << num << " ";
        if (i == 5)
            std::cout << "[...] ";
    }

    struct timeval start_vec, end_vec;
    gettimeofday(&start_vec, NULL);
    fordJohnsonSortVector();
    gettimeofday(&end_vec, NULL);
    double dur_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1e6
                   + (end_vec.tv_usec - start_vec.tv_usec);

    struct timeval start_deq, end_deq;
    gettimeofday(&start_deq, NULL);
    fordJohnsonSortDeque();
    gettimeofday(&end_deq, NULL);
    double dur_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1e6
                   + (end_deq.tv_usec - start_deq.tv_usec);

    std::cout << "\nAfter: ";
    for (size_t i = 0; i < vec.size() && i < 4; ++i)
        std::cout << vec[i] << " ";
    if (vec.size() > 4)
        std::cout << "[...] ";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << dur_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << dur_deq << " us" << std::endl;
}


// ─────────────────────────────────────────────────────────────────────────────
//  Jacobsthal sequence
//
//  J(0) = 0,  J(1) = 1,  J(k) = J(k-1) + 2 * J(k-2)
//  Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, …
//
//  Ford-Johnson uses these numbers to decide which pending (small) elements
//  to insert first.  Inserting in this order keeps the worst-case binary
//  search length minimal — each group of size J(k)-J(k-1) can be inserted
//  into a chain whose length is always a power-of-two minus 1.
// ─────────────────────────────────────────────────────────────────────────────

int PmergeMe::jacobsthal(int k) const
{
    if (k <= 0)
        return 0;
    if (k == 1)
        return 1;
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= k; ++i)
    {
        int next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

// Build the insertion order for `m` pending elements (0-based indices).
//
// Ford-Johnson groups:
//   Group 1 : index 0          (b1  — always inserted first)
//   Group 2 : indices [1, 2]   (J(2)-1 down to J(1))
//   Group k : indices [J(k-1), J(k)-1]  inserted in DESCENDING order
//
// Inserting the group in descending order within each group is critical:
// it ensures the upper bound for binary search never grows between
// consecutive insertions inside the same group.
std::vector<size_t> PmergeMe::buildInsertionOrder(size_t m) const
{
    std::vector<size_t> order;
    if (m == 0)
        return order;

    // b1 (index 0) is always first
    order.push_back(0);

    // Walk through Jacobsthal groups k = 2, 3, 4, …
    // until the group floor exceeds the available indices.
    for (int k = 2; ; ++k)
    {
        int jCurr = jacobsthal(k);
        int jPrev = jacobsthal(k - 1);

        // Clamp to actual number of pending elements (0-based ceiling = m-1)
        int hi = static_cast<int>(m) - 1;
        if (jCurr - 1 < hi)
            hi = jCurr - 1;

        int lo = jPrev; // 0-based inclusive floor for this group

        if (lo > static_cast<int>(m) - 1)
            break;

        // Insert this group in descending index order
        for (int i = hi; i >= lo; --i)
            order.push_back(static_cast<size_t>(i));

        if (jCurr >= static_cast<int>(m))
            break;
    }

    return order;
}


// ─────────────────────────────────────────────────────────────────────────────
//  Binary insertion helpers
//
//  `hiLimit` is the exclusive upper bound for the search range.
//  Passing the winner's position + 1 as hiLimit is the key Ford-Johnson
//  optimisation: we already know the small is ≤ its paired large, so there
//  is no point comparing against anything beyond the large's position.
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::binaryInsertVector(std::vector<int>& sorted,
                                   int               value,
                                   size_t            hiLimit) const
{
    size_t lo = 0;
    size_t hi = hiLimit;
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    sorted.insert(sorted.begin() + static_cast<std::ptrdiff_t>(lo), value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& sorted,
                                  int              value,
                                  size_t           hiLimit) const
{
    size_t lo = 0;
    size_t hi = hiLimit;
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    sorted.insert(sorted.begin() + static_cast<std::ptrdiff_t>(lo), value);
}

// Return position_of(winner) + 1  as the exclusive upper bound.
// Because winners were sorted recursively and are unique, lower_bound
// lands on the winner exactly.
size_t PmergeMe::winnerBoundVector(const std::vector<int>& sorted, int winner) const
{
    size_t lo = 0;
    size_t hi = sorted.size();
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < winner)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo + 1; // +1 so the winner itself is included as a valid ceiling
}

size_t PmergeMe::winnerBoundDeque(const std::deque<int>& sorted, int winner) const
{
    size_t lo = 0;
    size_t hi = sorted.size();
    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < winner)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo + 1;
}


// ─────────────────────────────────────────────────────────────────────────────
//  Ford-Johnson (merge-insertion) sort — std::vector
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::fordJohnsonSortVector()
{
    std::vector<int>& a = vec;
    size_t n = a.size();
    if (n <= 1)
        return;

    // ── Step 1: pair elements, sort each pair so large > small ───────────────
    size_t m = n / 2;
    std::vector<int> larges;
    std::vector<int> smalls;
    larges.reserve(m);
    smalls.reserve(m);

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int x = a[i];
        int y = a[i + 1];
        if (x < y)
        {
            smalls.push_back(x);
            larges.push_back(y);
        }
        else
        {
            smalls.push_back(y);
            larges.push_back(x);
        }
    }

    // Stash the leftover element when n is odd.
    // We use a bool flag instead of a sentinel so any integer value is valid.
    bool  hasOdd = (n % 2 == 1);
    int   oddVal = hasOdd ? a.back() : 0;

    // ── Step 2: recursively sort the larges (winners) ─────────────────────
    // We must remember which small was paired with which large BEFORE the
    // recursive sort changes their order.  We key the mapping by value;
    // this is safe because all larges are distinct (strict > comparison).
    std::vector<int> largesBefore = larges;

    if (!larges.empty())
    {
        PmergeMe tmp;
        tmp.vec = larges;
        tmp.fordJohnsonSortVector();
        larges = tmp.vec;
    }

    // Rebuild smalls in the same order as the now-sorted larges,
    // so smalls[i] is always the partner of larges[i].
    std::map<int, int> pairMap;
    for (size_t i = 0; i < m; ++i)
        pairMap[largesBefore[i]] = smalls[i];

    std::vector<int> pendingSmalls(m);
    for (size_t i = 0; i < m; ++i)
        pendingSmalls[i] = pairMap[larges[i]];

    // ── Step 3: start the sorted chain with all larges ────────────────────
    std::vector<int> sorted = larges;

    // ── Step 4: insert pending smalls in Ford-Johnson (Jacobsthal) order ──
    std::vector<size_t> order = buildInsertionOrder(m);

    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx    = order[k];
        int    small  = pendingSmalls[idx];
        int    large  = larges[idx];
        size_t bound  = winnerBoundVector(sorted, large);
        binaryInsertVector(sorted, small, bound);
    }

    // ── Step 5: insert the odd element (if any) into the full sorted chain ─
    if (hasOdd)
        binaryInsertVector(sorted, oddVal, sorted.size());

    for (size_t i = 0; i < n; ++i)
        a[i] = sorted[i];
}


// ─────────────────────────────────────────────────────────────────────────────
//  Ford-Johnson (merge-insertion) sort — std::deque
//  (mirrors the vector version exactly)
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::fordJohnsonSortDeque()
{
    std::deque<int>& d = deq;
    size_t n = d.size();
    if (n <= 1)
        return;

    size_t m = n / 2;
    std::deque<int> larges;
    std::deque<int> smalls;

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int x = d[i];
        int y = d[i + 1];
        if (x < y)
        {
            smalls.push_back(x);
            larges.push_back(y);
        }
        else
        {
            smalls.push_back(y);
            larges.push_back(x);
        }
    }

    bool hasOdd = (n % 2 == 1);
    int  oddVal = hasOdd ? d.back() : 0;

    std::deque<int> largesBefore = larges;

    if (!larges.empty())
    {
        PmergeMe tmp;
        tmp.deq = larges;
        tmp.fordJohnsonSortDeque();
        larges = tmp.deq;
    }

    std::map<int, int> pairMap;
    for (size_t i = 0; i < m; ++i)
        pairMap[largesBefore[i]] = smalls[i];

    std::deque<int> pendingSmalls(m);
    for (size_t i = 0; i < m; ++i)
        pendingSmalls[i] = pairMap[larges[i]];

    std::deque<int> sorted = larges;

    std::vector<size_t> order = buildInsertionOrder(m);

    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx   = order[k];
        int    small = pendingSmalls[idx];
        int    large = larges[idx];
        size_t bound = winnerBoundDeque(sorted, large);
        binaryInsertDeque(sorted, small, bound);
    }

    if (hasOdd)
        binaryInsertDeque(sorted, oddVal, sorted.size());

    for (size_t i = 0; i < n; ++i)
        d[i] = sorted[i];
}
