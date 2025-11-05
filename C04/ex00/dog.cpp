#include "dog.hpp"
Dog::Dog() : Animal("Dog") {
	std::cout << "Dog "  << " created." << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog " << " is destroyed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}