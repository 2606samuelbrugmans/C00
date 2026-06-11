#include "PmergeMe.hpp"
//./PmergeMe $(shuf -i 1-1000000 -n 100000 | tr '\n' ' ')
// -i is the range and -n is the numbers of numbers
// this command doesnt generate duplicates 
int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "need at least one number" << std::endl;
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.sortAndDisplayWithTiming(argv, argc);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
