#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include <string>

#include "WrongAnimal.hpp"
class Wrongcat : public WrongAnimal {
  public:
	Wrongcat();
	~Wrongcat();
	void makeSound() const;
};
#endif