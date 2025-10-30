#include "HumanA.hpp"

humanA::humanA(std::string n, Weapon &w) : name(n), sword(&w) {}
humanA::~humanA() {}

void humanA::attack() {
	std::cout << name << " attacks with their " << sword->getType() << std::endl;
}
void humanA::setWeapon(Weapon &w) {
	sword = &w;
}