#pragma once
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>

#include <string>
#include <iostream>
#include <vector>
#include <sstream>


class Span {
   public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int shortestSpan() const;
	int longestSpan() const;

   private:
	unsigned int maxSize;
	std::vector<int> numbers;
};
