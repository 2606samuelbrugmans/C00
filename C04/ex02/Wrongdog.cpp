#include "Wrongdog.hpp"
Wrongdog::Wrongdog() : WrongAnimal("WrongDog") {
	std::cout << "WrongDog " << " created." << std::endl;
}
Wrongdog::~Wrongdog() {
	std::cout << "WrongDog " << " is destroyed." << std::endl;
}
void Wrongdog::makeSound() const {
	std::cout << "woof" << std::endl;
}
