#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <map>
# include <set>
# include <stdexcept>
# include <iomanip>
# include <cstdlib>
# include <sys/time.h>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

        void sortAndDisplay(char **argv, int argc);
        void sortAndDisplayWithTiming(char **argv, int argc);

    private:
        std::vector<int> vec;
        std::deque<int>  deq;

        // Jacobsthal helpers
        int                  jacobsthal(int k) const;
        std::vector<size_t>  buildInsertionOrder(size_t m) const;

        // Binary insertion
        void    binaryInsertVector(std::vector<int>& sorted, int value, size_t hiLimit) const;
        void    binaryInsertDeque (std::deque<int>&  sorted, int value, size_t hiLimit) const;

        // Upper-bound helpers
        size_t  winnerBoundVector(const std::vector<int>& sorted, int winner) const;
        size_t  winnerBoundDeque (const std::deque<int>&  sorted, int winner) const;

        // Core sorts
        void    fordJohnsonSortVector();
        void    fordJohnsonSortDeque();
};

#endif
