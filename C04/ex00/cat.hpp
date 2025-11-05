#ifndef CAT_HPP
#define CAT_HPP


#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal {
  public:
	Cat();
	~Cat();
	void makeSound() const; // Override makeSound method
};

#endif