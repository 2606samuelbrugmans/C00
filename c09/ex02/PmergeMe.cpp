#include "PmergeMe.hpp"


PmergeMe::PmergeMe() { }
PmergeMe::~PmergeMe() { }



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
//   Group 1 : index 0          (b1 — always inserted first)
//   Group k : indices [J(k-1), J(k)-1]  inserted in DESCENDING order
//
// Descending order within each group keeps the binary-search upper bound
// from growing between consecutive insertions in the same group.
std::vector<size_t> PmergeMe::buildInsertionOrder(size_t m) const
{
    std::vector<size_t> order;
    if (m == 0)
        return order;

    order.push_back(0);

    for (int k = 2; ; ++k)
    {
        int jCurr = jacobsthal(k);
        int jPrev = jacobsthal(k - 1);

        int hi = static_cast<int>(m) - 1;
        if (jCurr - 1 < hi)
            hi = jCurr - 1;

        int lo = jPrev;

        if (lo > static_cast<int>(m) - 1)
            break;

        for (int i = hi; i >= lo; --i)
            order.push_back(static_cast<size_t>(i));

        if (jCurr >= static_cast<int>(m))
            break;
    }

    return order;
}


// ─────────────────────────────────────────────────────────────────────────────
//  Binary insertion helpers
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
    return lo + 1;
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
//  Pair-sorting helpers
//
//  Instead of keeping separate large/small vectors and using a map to
//  reconnect them after recursion, we store each (large, small) duo as a
//  std::pair<int,int> and sort the pair-vector by .first.
//  The small travels with its large at every recursion level, so no lookup
//  is ever needed.
//
//  sortPairsVector / sortPairsDeque both use the same logic; the only
//  difference is which container type they are called from (kept separate
//  to mirror the vector/deque split of the main sort functions).
// ─────────────────────────────────────────────────────────────────────────────

typedef std::vector<std::pair<int, int> > PairVec;

void PmergeMe::sortPairsVector(PairVec& pairs)
{
    size_t n = pairs.size();
    if (n <= 1)
        return;

    // Build (winner-pair, loser-pair) from each consecutive duo.
    // winner = the pair whose .first is larger.
    PairVec winners;
    PairVec losers;
    winners.reserve(n / 2);
    losers.reserve(n / 2);

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        if (pairs[i].first >= pairs[i + 1].first)
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }
    if (n % 2 == 1)
        losers.push_back(pairs.back());

    sortPairsVector(winners);

    // Merge losers into winners with binary insertion on .first
    for (size_t i = 0; i < losers.size(); ++i)
    {
        int    val = losers[i].first;
        size_t lo  = 0;
        size_t hi  = winners.size();
        while (lo < hi)
        {
            size_t mid = lo + (hi - lo) / 2;
            if (winners[mid].first < val)
                lo = mid + 1;
            else
                hi = mid;
        }
        winners.insert(winners.begin() + static_cast<std::ptrdiff_t>(lo), losers[i]);
    }

    pairs = winners;
}

void PmergeMe::sortPairsDeque(PairVec& pairs)
{
    size_t n = pairs.size();
    if (n <= 1)
        return;

    PairVec winners;
    PairVec losers;
    winners.reserve(n / 2);
    losers.reserve(n / 2);

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        if (pairs[i].first >= pairs[i + 1].first)
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }
    if (n % 2 == 1)
        losers.push_back(pairs.back());

    sortPairsDeque(winners);

    for (size_t i = 0; i < losers.size(); ++i)
    {
        int    val = losers[i].first;
        size_t lo  = 0;
        size_t hi  = winners.size();
        while (lo < hi)
        {
            size_t mid = lo + (hi - lo) / 2;
            if (winners[mid].first < val)
                lo = mid + 1;
            else
                hi = mid;
        }
        winners.insert(winners.begin() + static_cast<std::ptrdiff_t>(lo), losers[i]);
    }

    pairs = winners;
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

    size_t m = n / 2;

    // ── Step 1: build (large, small) pairs ───────────────────────────────────
    PairVec pairs;
    pairs.reserve(m);

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int x = a[i];
        int y = a[i + 1];
        if (x >= y)
            pairs.push_back(std::make_pair(x, y));
        else
            pairs.push_back(std::make_pair(y, x));
    }

    bool hasOdd = (n % 2 == 1);
    int  oddVal = 0;
    if (hasOdd)
        oddVal = a.back();

    // ── Step 2: sort pairs recursively by their large (.first) ───────────────
    sortPairsVector(pairs);

    // ── Step 3: seed the sorted chain with all larges ────────────────────────
    std::vector<int> sorted;
    sorted.reserve(n);
    for (size_t i = 0; i < m; ++i)
        sorted.push_back(pairs[i].first);

    // ── Step 4: insert smalls in Jacobsthal order ────────────────────────────
    std::vector<size_t> order = buildInsertionOrder(m);

    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx   = order[k];
        int    small = pairs[idx].second;
        int    large = pairs[idx].first;
        size_t bound = winnerBoundVector(sorted, large);
        binaryInsertVector(sorted, small, bound);
    }

    // ── Step 5: insert the odd element if present ────────────────────────────
    if (hasOdd)
        binaryInsertVector(sorted, oddVal, sorted.size());

    for (size_t i = 0; i < n; ++i)
        a[i] = sorted[i];
}


// ─────────────────────────────────────────────────────────────────────────────
//  Ford-Johnson (merge-insertion) sort — std::deque
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::fordJohnsonSortDeque()
{
    std::deque<int>& d = deq;
    size_t n = d.size();
    if (n <= 1)
        return;

    size_t m = n / 2;

    PairVec pairs;
    pairs.reserve(m);

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int x = d[i];
        int y = d[i + 1];
        if (x >= y)
            pairs.push_back(std::make_pair(x, y));
        else
            pairs.push_back(std::make_pair(y, x));
    }

    bool hasOdd = (n % 2 == 1);
    int  oddVal = 0;
    if (hasOdd)
        oddVal = d.back();

    sortPairsDeque(pairs);

    std::deque<int> sorted;
    for (size_t i = 0; i < m; ++i)
        sorted.push_back(pairs[i].first);

    std::vector<size_t> order = buildInsertionOrder(m);

    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx   = order[k];
        int    small = pairs[idx].second;
        int    large = pairs[idx].first;
        size_t bound = winnerBoundDeque(sorted, large);
        binaryInsertDeque(sorted, small, bound);
    }

    if (hasOdd)
        binaryInsertDeque(sorted, oddVal, sorted.size());

    for (size_t i = 0; i < n; ++i)
        d[i] = sorted[i];
}
