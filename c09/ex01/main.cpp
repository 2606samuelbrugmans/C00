#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "enter a list of numbers surrounded by \" \" " << std::endl;
		return 1;
	}
	else 
	{
		RPN rpn;
		rpn.evaluate(argv[1]);
	}
}