#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <string>
#include <limits>
const int INT32_MIN = -2147483648;
const int INT32_MAX = 2147483647;
const double FLOAT_MIN = -3.4e+38;
const double FLOAT_MAX = 3.4e+38;
const double DOUBLE_MIN = -1.7e+308;
const double DOUBLE_MAX = 1.7e+308;
const int charType = 0;
const int intType = 1;
const int floatType = 2;
const int doubleType = 3;

class ScalarConverter {

	private :
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter& operator=( const ScalarConverter& other );
	~ScalarConverter( void );
	static void convertChar(const std::string &ToConvert);
	static void convertInt(const std::string &ToConvert);
	static void convertFloat(const std::string &ToConvert);
	static void convertDouble(const std::string &ToConvert);
	static int detectType(const std::string &ToConvert);
	static int specialType(const std::string &ToConvert);
	public :
	static void convert(const std::string &ToConvert);

	
};



#endif