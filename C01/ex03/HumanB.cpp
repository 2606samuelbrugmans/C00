#include "HumanB.hpp"

humanB::humanB(std::string n) : name(n), club(NULL) {}
humanB::~humanB() {}

void humanB::attack() {
	if (club)
		std::cout << name << " attacks with their " << club->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with!" << std::endl;
}
void humanB::setWeapon(Weapon &w) {
	club = &w;
}