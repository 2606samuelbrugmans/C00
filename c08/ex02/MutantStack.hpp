#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

class MutantStack : public std::stack<int> {
   public:
	MutantStack() : std::stack<int>() {}
	MutantStack(const MutantStack& other) : std::stack<int>(other) {}
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<int>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<int>::container_type::iterator iterator;
	typedef typename std::stack<int>::container_type::const_iterator const_iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}
};