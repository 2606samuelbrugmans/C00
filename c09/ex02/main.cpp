#include "PmergeMe.hpp"
#include <iostream>

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
