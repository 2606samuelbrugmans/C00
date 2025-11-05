#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;

	public:
		Dog();
		~Dog();
		Dog(Dog const &other);
		void makeSound() const; 
		Animal* clone() const { return new Dog(*this); }
		Brain *getBrain() const { return brain; }
		Dog &operator=(Dog const &other);
};
#endif