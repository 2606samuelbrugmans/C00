#include "Scavetrap.hpp"

Scavetrap::Scavetrap(std::string n) : Claptrap(n) {
	hitpoints = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "Scavetrap " << name << " created with " << hitpoints << " hitpoints, "
			  << energy_points << " energy points, and " << attack_damage << " attack damage." << std::endl;
}

Scavetrap::~Scavetrap() {
	std::cout << "Scavetrap " << name << " is destroyed!" << std::endl;
}
void Scavetrap::guardGate() {
	if (hitpoints <= 0) {
		std::cout << "Scavetrap " << name << " has no hitpoints left and cannot enter Gate Keeper mode!" << std::endl;
		return;
	}
	std::cout << "Scavetrap " << name << " is now in Gate Keeper mode." << std::endl;
}
void Scavetrap::attack(const std::string &target) {
	if (energy_points <= 0) {
		std::cout << "Scavetrap " << name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (hitpoints <= 0) {
		std::cout << "Scavetrap " << name << " has no hitpoints left and cannot attack!" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "Scavetrap " << name << " attacks " << target << ", causing "
			  << attack_damage << " points of damage! "
			  << "(" << energy_points << " energy points left)" << std::endl;
}
