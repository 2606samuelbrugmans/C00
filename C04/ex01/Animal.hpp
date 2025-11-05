#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
#include <string>
class Animal {
  protected:
	std::string type;

  public:
	Animal();
	Animal(std::string t);
	virtual ~Animal();
	virtual void makeSound() const;
	virtual Brain* getBrain() const { return NULL; }
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	std::string getType() const;

};

#endif