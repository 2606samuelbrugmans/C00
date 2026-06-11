#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <set>
# include <stdexcept>
# include <iomanip>
# include <cstdlib>
# include <sys/time.h>

// Convenience alias — a (large, small) pair produced during the pairing step.
// Using a typedef keeps the declarations below readable without C++11 'using'.
typedef std::vector<std::pair<int, int> > PairVec;

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

        // Pair-sorting (recursive Ford-Johnson on the (large,small) pairs)
        void    sortPairsVector(PairVec& pairs);
        void    sortPairsDeque (PairVec& pairs);

        // Binary insertion into the final sorted chain
        void    binaryInsertVector(std::vector<int>& sorted, int value, size_t hiLimit) const;
        void    binaryInsertDeque (std::deque<int>&  sorted, int value, size_t hiLimit) const;

        // Upper-bound for a small's binary search: position of its paired large + 1
        size_t  winnerBoundVector(const std::vector<int>& sorted, int winner) const;
        size_t  winnerBoundDeque (const std::deque<int>&  sorted, int winner) const;

        // Core sorts
        void    fordJohnsonSortVector();
        void    fordJohnsonSortDeque();
};

#endif
