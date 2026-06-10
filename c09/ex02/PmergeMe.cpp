#include "PmergeMe.hpp"
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

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
    for (int i = 1; i < argc; ++i)
    {
        char *endptr = NULL;
        long val = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0')        
            throw std::runtime_error("Error : invalid number '" + std::string(argv[i]) + "'");
        if (val < 0)
            throw std::runtime_error("Error : number '" + std::string(argv[i]) + "' is negative");
        int num = static_cast<int>(val);
        vec.push_back(num);
        deq.push_back(num);
        if (i < 5) // only print the first few numbers to avoid clutter
            std::cout << num << " ";
        if (i == 5)
            std::cout << "[...] ";
    }

    struct timeval start_vec, end_vec;
    gettimeofday(&start_vec, NULL);
    fordJohnsonSortVector();
    gettimeofday(&end_vec, NULL);
    double dur_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1e6 + (end_vec.tv_usec - start_vec.tv_usec);

    struct timeval start_deq, end_deq;
    gettimeofday(&start_deq, NULL);
    fordJohnsonSortDeque();
    gettimeofday(&end_deq, NULL);
    double dur_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1e6 + (end_deq.tv_usec - start_deq.tv_usec);

    std::cout << "\nAfter: ";
    for (size_t i = 0; i < vec.size() && i < 4; ++i)
        std::cout << vec[i] << " ";
    if (vec.size() > 4)
        std::cout << "[...] ";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << dur_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << dur_deq << " us" << std::endl;
}

// -------------------- Ford-Johnson (merge-insertion) helpers --------------------
// Compute Jacobsthal number J(k): J0=0, J1=1, Jk = Jk-1 + 2*Jk-2
int PmergeMe::jacobsthal(int k) const
{
    if (k <= 0) return 0;
    if (k == 1) return 1;
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 2; i <= k; ++i) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

std::vector<int> PmergeMe::jacobOrderIndices(size_t m) const
{
    std::vector<int> order;
    if (m == 0) return order;
    std::vector<char> seen(m, 0);
    for (int k = 1; ; ++k) {
        int j = jacobsthal(k);
        if (j <= 0) continue;
        int idx = j - 1; // convert to 0-based index
        if (idx <= 0) continue; // skip 0 to avoid duplicating the first small
        if ((size_t)idx >= m) break;
        if (!seen[idx]) {
            order.push_back(idx);
            seen[idx] = 1;
        }
    }
    return order;
}

void PmergeMe::binaryInsertVector(std::vector<int>& sorted, int value) const
{
    size_t lo = 0;
    size_t hi = sorted.size();
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < value) lo = mid + 1;
        else hi = mid;
    }
    sorted.insert(sorted.begin() + lo, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& sorted, int value) const
{
    size_t lo = 0;
    size_t hi = sorted.size();
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < value) lo = mid + 1;
        else hi = mid;
    }
    sorted.insert(sorted.begin() + lo, value);
}

void PmergeMe::fordJohnsonSortVector()
{
    std::vector<int>& a = vec;
    size_t n = a.size();
    if (n <= 1) return;

    size_t m = n / 2;
    std::vector<int> larges;
    std::vector<int> smalls;
    larges.reserve(m);
    smalls.reserve(m);
    for (size_t i = 0; i + 1 < n; i += 2) {
        int x = a[i];
        int y = a[i+1];
        if (x < y) { smalls.push_back(x); larges.push_back(y); }
        else { smalls.push_back(y); larges.push_back(x); }
    }
    int odd = -1;
    if (n % 2 == 1) odd = a.back();

    // recursively sort larges
    if (!larges.empty()) {
        PmergeMe temp;
        temp.vec = larges;
        temp.fordJohnsonSortVector();
        larges = temp.vec;
    }

    std::vector<int> sorted = larges;
    if (!smalls.empty()) sorted.insert(sorted.begin(), smalls[0]);

    std::vector<int> order = jacobOrderIndices(m);
    std::vector<char> inserted(m, 0);
    if (m > 0) inserted[0] = 1;
    for (size_t idx = 0; idx < order.size(); ++idx) {
        int pairIdx = order[idx];
        if ((size_t)pairIdx < m && !inserted[pairIdx]) {
            binaryInsertVector(sorted, smalls[pairIdx]);
            inserted[pairIdx] = 1;
        }
    }
    for (size_t i = 0; i < m; ++i) if (!inserted[i]) binaryInsertVector(sorted, smalls[i]);
    if (odd != -1) binaryInsertVector(sorted, odd);

    for (size_t i = 0; i < n; ++i) a[i] = sorted[i];
}

void PmergeMe::fordJohnsonSortDeque()
{
    std::deque<int>& d = deq;
    size_t n = d.size();
    if (n <= 1) return;

    size_t m = n / 2;
    std::deque<int> larges;
    std::deque<int> smalls;
    for (size_t i = 0; i + 1 < n; i += 2) {
        int x = d[i];
        int y = d[i+1];
        if (x < y) { smalls.push_back(x); larges.push_back(y); }
        else { smalls.push_back(y); larges.push_back(x); }
    }
    int odd = -1;
    if (n % 2 == 1) odd = d.back();

    // recursively sort larges
    if (!larges.empty()) {
        PmergeMe temp;
        temp.deq = larges;
        temp.fordJohnsonSortDeque();
        larges = temp.deq;
    }

    std::deque<int> sorted = larges;
    if (!smalls.empty()) sorted.push_front(smalls[0]);

    std::vector<int> order = jacobOrderIndices(m);
    std::vector<char> inserted(m, 0);
    if (m > 0) inserted[0] = 1;
    for (size_t idx = 0; idx < order.size(); ++idx) {
        int pairIdx = order[idx];
        if ((size_t)pairIdx < m && !inserted[pairIdx]) {
            binaryInsertDeque(sorted, smalls[pairIdx]);
            inserted[pairIdx] = 1;
        }
    }
    for (size_t i = 0; i < m; ++i) if (!inserted[i]) binaryInsertDeque(sorted, smalls[i]);
    if (odd != -1) binaryInsertDeque(sorted, odd);

    for (size_t i = 0; i < n; ++i) d[i] = sorted[i];
}
