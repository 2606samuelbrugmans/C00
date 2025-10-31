#include "Flagtrap.hpp"

Flagtrap::Flagtrap(std::string n) : Claptrap(n) {
	hitpoints = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "Flagtrap " << name << " created with " << hitpoints << " hitpoints, "
			  << energy_points << " energy points, and " << attack_damage << " attack damage." << std::endl;
}
Flagtrap::~Flagtrap() {
	std::cout << "Flagtrap " << name << " is destroyed" << std::endl;
}
void Flagtrap::highFivesGuys() {
	std::cout << "Flagtrap " << name << " requests a high five! ✋" << std::endl;
}
void Flagtrap::attack(const std::string &target) {
	if (energy_points <= 0) {
		std::cout << "Flagtrap " << name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (hitpoints <= 0) {
		std::cout << "Flagtrap " << name << " has no hitpoints left and cannot attack!" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "Flagtrap " << name << " attacks " << target << ", causing "
			  << attack_damage << " points of damage! "
			  << "(" << energy_points << " energy points left)" << std::endl;
}
