#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stdexcept>

class PmergeMe
{
public:
	PmergeMe();	
	~PmergeMe();

	void sortAndDisplay(char **argv, int argc);
	void sortAndDisplayWithTiming(char **argv, int argc);

private:
	std::vector<int> vec;
	std::deque<int> deq;

	// Ford-Johnson helpers (moved from free functions)
	int jacobsthal(int k) const;
	std::vector<int> jacobOrderIndices(size_t m) const;
	void binaryInsertVector(std::vector<int>& sorted, int value) const;
	void binaryInsertDeque(std::deque<int>& sorted, int value) const;

	void fordJohnsonSortVector();
	void fordJohnsonSortDeque();
};

// No custom runtime error type needed; use std::runtime_error directly when required.