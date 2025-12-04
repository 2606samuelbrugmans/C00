#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cerrno>

ScalarConverter::ScalarConverter( void )
{
    
}
ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
	(void)other;
}
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter( void )
{
}
int ScalarConverter::specialType(const std::string &ToConvert)
{
    std::string special_literals[8] = {
        "inf",
        "+inf",
        "inff",
        "+inff",
        "-inf",
        "-inff",
        "nan",
        "nanf"
    };

    for (int i = 0; i < 8; i++)
    {
        if (ToConvert == special_literals[i])
            return i;  
    }
    return -1;
}
void ScalarConverter::convertChar(const std::string &ToConvert)
{
	int converted;
	// If it's a single printable non-digit character, treat it as a char literal
	if (specialType(ToConvert) != -1)
	{
		std::cerr << "char: impossible" << std::endl;
		return;
	}
	if (ToConvert.length() == 1 && !isdigit(static_cast<unsigned char>(ToConvert[0])))
	{
		converted = static_cast<int>(ToConvert[0]);
	}
	else
	{
		double d = atof(ToConvert.c_str());
		converted = static_cast<int>(d);
	}

	if (converted < 0 || converted > 127)
	{
		std::cerr << "char: impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(converted);
	if (c < 32 || c == 127)
	{
		std::cerr << "char: Non displayable" << std::endl;
		return;
	}

	std::cout << "char: '" << c << "'" << std::endl;

}
void ScalarConverter::convertInt(const std::string &ToConvert)
{
	if (specialType(ToConvert) != -1)
	{
		std::cerr << "int: impossible" << std::endl;
		return;
	}
	if (ToConvert.length() == 1 && !std::isdigit(ToConvert[0]))
	{
    	char c = ToConvert[0];
    	std::cout << "int: " << static_cast<int>(c) << "\n";
		return ;
	}
	double converted = atof(ToConvert.c_str());
	if (converted < static_cast<double>(INT32_MIN) || converted > static_cast<double>(INT32_MAX))
	{
		std::cerr << "int: impossible" << std::endl;
		return;
	}
	else
	{
		int i = static_cast<int>(converted);
		std::cout << "int: " << i << std::endl;
	}

}
void ScalarConverter::convertFloat(const std::string &ToConvert)
{
	if (specialType(ToConvert) >= 6)
	{
		std::cerr << "float: nanf" << std::endl;
		return;
	}
	else if (specialType(ToConvert) >= 4)
	{
		std::cerr << "float: -inff" << std::endl;
		return;

	}
	else if (specialType(ToConvert) != -1)
	{
		std::cerr << "float: inff" << std::endl;
		return;

	}
	if (ToConvert.length() == 1 && !std::isdigit(ToConvert[0]))
	{
    	char c = ToConvert[0];
    	std::cout << "float: " << static_cast<float>(c) << "f\n";
    	return;
	}
	float f = static_cast<float>(atof(ToConvert.c_str()));
	double value = f;

	if (value > std::numeric_limits<float>::max() ||
    	value < -std::numeric_limits<float>::max())
	{
    	std::cout << "float: impossible\n";
	}
	else
	{
    	std::cout << "float: " << f << "f\n";
	}
}
int ScalarConverter::detectType(const std::string &ToConvert)
{
	int len = static_cast<int>(ToConvert.length());
	if (len == 1 && isprint(static_cast<unsigned char>(ToConvert[0])) && !isdigit(static_cast<unsigned char>(ToConvert[0])))
		return charType;
	if (specialType(ToConvert) == -1)
	{
		for (int i = 0; i < len; i++)
		{
		char ch = ToConvert[i];
		if (!isdigit(static_cast<unsigned char>(ch)) && ch != '.' 
			&& ch != '-' && ch != '+' && ch != 'f' && ch != 'F')
			return -1; // invalid
		}
	}
	if (ToConvert[len - 1] == 'f' || ToConvert[len - 1] == 'F')
		return floatType;
	if (ToConvert.find('.') != std::string::npos)
		return doubleType;

	if (ToConvert[len - 1] != 'f')
		return intType;
	return charType;
}
void ScalarConverter::convertDouble(const std::string &ToConvert)
{
	int len = static_cast<int>(ToConvert.length());

	if (specialType(ToConvert) >= 6)
	{
		std::cerr << "double: nan" << std::endl;
		return;
	}
	else if (specialType(ToConvert) >= 4)
	{
		std::cerr << "double: -inf" << std::endl;
		return;

	}
	else if (specialType(ToConvert) != -1)
	{
		std::cerr << "double: inf" << std::endl;
		return;

	}
	if (ToConvert.length() == 1 && !std::isdigit(ToConvert[0]))
	{
    	char c = ToConvert[0];
    	std::cout << "double: " << static_cast<double>(c) << "\n";
    	return;
	}
	if (len > 309 ) 
	{
		std::cerr << "double: impossible" << std::endl;
		return;
	}
	if (len > 308 && ToConvert[0] != '-' && ToConvert[0] != '+')
	{
		std::cerr << "double: impossible" << std::endl;
		return;
	}
	else if (ToConvert[0] ==  '-' && len > 309)
	{
		std::cerr << "double: impossible" << std::endl;
		return;
	}
	double converted = atof(ToConvert.c_str()); // Implementation for converting to double
	if (converted < DOUBLE_MIN || converted > DOUBLE_MAX)
	{
		std::cerr << "double: impossible" << std::endl;
		return;
	}
	std::cout << "double: " << converted << std::endl;

}



void ScalarConverter::convert(const std::string &ToConvert)
{

	if (ToConvert.empty())
		return ;

	if (detectType(ToConvert) != -1)
		{
				convertChar(ToConvert);
				convertInt(ToConvert);
				convertFloat(ToConvert);
				convertDouble(ToConvert);
				return ;
		}
	std::cerr << "Invalid input" << std::endl;
			return ;
}