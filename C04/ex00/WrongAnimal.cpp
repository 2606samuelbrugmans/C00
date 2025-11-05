#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal " << " created." << std::endl;
}
WrongAnimal::WrongAnimal(std::string t) : type(t) {
	std::cout << "WrongAnimal of type " << type << " created." << std::
endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << type << " is destroyed." << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &other) {
	type = other.type;
	std::cout << "WrongAnimal " << type << " copied." << std::endl;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "WrongAnimal " << type << " assigned." << std::endl;
	return *this;
}
void WrongAnimal::makeSound() const {
	std::cout << "some wrong animal sound" << std::endl;
}
std::string WrongAnimal::getType() const {
	return type;
}
