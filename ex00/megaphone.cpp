
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; ++i)
	{
		for (char* p = argv[i]; *p; ++p)
		{
			*p = std::toupper(*p);
		}
		std::cout << argv[i];
		std::cout << " ";
	}
	std::cout << std::endl;

	return 0;
}