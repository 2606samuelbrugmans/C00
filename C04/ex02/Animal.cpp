#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal " << " created." << std::endl;
}
Animal::Animal(std::string t) : type(t) {
	std::cout << "Animal of type " << type << " created." << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal " << type << " is destroyed." << std::endl;
}
Animal::Animal(Animal const &other) {
	type = other.type;
	std::cout << "Animal " << type << " copied." << std::endl;
}
Animal &Animal::operator=(Animal const &other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "Animal " << type << " assigned." << std::endl;
	return *this;
}
void Animal::makeSound() const {
	std::cout << "some animal sound" << std::endl;
}
std::string Animal::getType() const {
	return type;
}

