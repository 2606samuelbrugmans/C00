#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t) {}
Weapon::~Weapon() { 
        std::cout << type << " is destroyed!" << std::endl;
}

void Weapon::setType(const std::string& t) {
	type = t;
}

const std::string& Weapon::getType() const {
	return type;
}
