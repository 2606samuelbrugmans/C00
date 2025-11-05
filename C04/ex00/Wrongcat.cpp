#include "Wrongcat.hpp"
Wrongcat::Wrongcat() : WrongAnimal("Wrongcat") {
	std::cout << "Wrongcat " << " created." << std::endl;
}
Wrongcat::~Wrongcat() {
	std::cout << "Wrongcat " << " is destroyed." << std::endl;
}
void Wrongcat::makeSound() const {
	std::cout << "meow" << std::endl;
}

