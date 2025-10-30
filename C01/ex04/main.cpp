#include "Sed.hpp"



int main()
{

	Sed file("Makefile", "c++", "g++");
	file.replace();
	Sed two("", "c++", "g++");
	two.replace();
	Sed three("Makefile", "", "g++");
	three.replace();
	return 0;
}