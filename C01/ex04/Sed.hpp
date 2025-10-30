#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
private:
	std::string filename;
	std::string s1;
	std::string s2;

public:
	Sed(std::string file, std::string str1, std::string str2);
	~Sed();

	void replace();
};

#endif