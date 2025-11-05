#include "dog.hpp"
Dog::Dog() : Animal("Dog") {
	brain = new Brain();
	std::cout << "Dog "  << " created." << std::endl;
}
Dog::~Dog() {
	delete brain;
	std::cout << "Dog " << " is destroyed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog " << type << " assigned." << std::endl;
	return *this;
}
Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);  
}