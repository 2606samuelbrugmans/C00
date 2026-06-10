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
		try
		{
			RPN rpn;
			rpn.evaluate(argv[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return 1;
		}
	}
}