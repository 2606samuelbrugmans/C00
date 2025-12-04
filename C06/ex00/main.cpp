#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "Usage: ./scalar_converter <literal_value>" << std::endl;
		return 1;
	}

	std::string input = argv[1];
	ScalarConverter::convert(input);

	return 0;
}