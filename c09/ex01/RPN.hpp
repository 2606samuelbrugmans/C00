#pragma once
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <iostream>
#include <stdexcept>

class RPN {
public:
	RPN();
	~RPN();
	void evaluate(const std::string& expression);
private:
	bool isOperator(char c);
	void applyOperator(std::stack<int> &reserve, int stackEmpty, char op);
	std::stack<int> reserve;
};
class errorRuntime : public std::runtime_error {
public:
	errorRuntime(const std::string& message)
		: std::runtime_error(message) {}
};
