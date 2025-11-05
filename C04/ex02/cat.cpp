#include "cat.hpp"
Cat::Cat() : Animal("Cat") {
	brain = new Brain();
	std::cout << "Cat "  << " created." << std::endl;
}
Cat::~Cat() {
	delete brain;
	std::cout << "Cat " << " is destroyed." << std::endl;
}
void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat " << type << " assigned." << std::endl;
	return *this;
}
Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
}