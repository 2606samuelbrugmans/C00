#ifndef CAT_HPP
#define CAT_HPP


#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain *brain;
	

  	public:
		Cat();
		~Cat();
		void makeSound() const; // Override makeSound method
		Brain *getBrain() const { return brain; }
		Animal* clone() const { return new Cat(*this); }
		Cat &operator=(Cat const &other);
		Cat(Cat const &other);


};

#endif