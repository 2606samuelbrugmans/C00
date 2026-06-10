#include "RPN.hpp"

RPN::RPN()
{};

RPN::~RPN()
{};
bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
void RPN::applyOperator(std::stack<int> &reserve, int stackEmpty, char op)
{
	int right;
	int left;
	if (stackEmpty < 2)
		throw (errorRuntime("Error: not enough numbers in the stack"));
	right = reserve.top();
	reserve.pop();
	left = reserve.top();
	reserve.pop();
	switch (op)
	{
	case '+':
		reserve.push(left + right);
		break;
	case '-':
		reserve.push(left - right);
		break;
	case '*':
		reserve.push(left * right);
		break;
	case '/':
		if (right == 0)
			throw (errorRuntime("Error: division by zero"));
		reserve.push(left / right);
		break;
	default:
		throw (errorRuntime("Error: invalid operator"));
	}
}
void RPN::evaluate(const std::string& expression)
{
	int i = 0;
	int len = expression.length();
	int has_number = 0;
	while (i < len )
	{
		if (isOperator(expression[i]) && has_number == 0)
			throw (errorRuntime("Error: not enough numbers in the stack"));
		else if (isOperator(expression[i]))
		{

			applyOperator(reserve,has_number, expression[i]);
			has_number--;
		}
		else if ( isdigit(expression[i]))
		{
			reserve.push(expression[i] - '0');
			has_number++;
		}
		else 
		{
			if (!isspace(expression[i]))
				throw (errorRuntime("Error: invalid character found"));
		}
		i++;
	}
	std::cout << "Result: " << reserve.top() << std::endl;
}
