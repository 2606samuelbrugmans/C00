#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
class Wrongdog : public WrongAnimal {
	public:
	Wrongdog();
	~Wrongdog();
	void makeSound() const;
};
#endif