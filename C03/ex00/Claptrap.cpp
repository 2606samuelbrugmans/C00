#include "Claptrap.hpp"

Claptrap::Claptrap() : name("Default"), hitpoints(10), energy_points(10), attack_damage(0) {
	std::cout << "Claptrap " << name << " created with " << hitpoints << " hitpoints, "
			  << energy_points << " energy points, and " << attack_damage << " attack damage." << std::endl;
}

Claptrap::Claptrap(std::string n) : name(n), hitpoints(10), energy_points(10), attack_damage(0) {
	std::cout << "Claptrap " << name << " created with " << hitpoints << " hitpoints, "
			  << energy_points << " energy points, and " << attack_damage << " attack damage." << std::endl;
}
Claptrap::Claptrap(Claptrap const &other) {
	name = other.name;
	hitpoints = other.hitpoints;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << "Claptrap " << name << " copied" << std::endl;
}

Claptrap &Claptrap::operator=(Claptrap const &other) {
	if (this != &other) {
		name = other.name;
		hitpoints = other.hitpoints;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	std::cout << "Claptrap " << name << " assigned" << std::endl;
	return *this;
}

Claptrap::~Claptrap() {
	std::cout << "Claptrap " << name << " is destroyed" << std::endl;
}
void Claptrap::attack(const std::string &target) {
	if (energy_points <= 0) {
		std::cout << "Claptrap " << name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (hitpoints <= 0) {
		std::cout << "Claptrap " << name << " has no hitpoints left and cannot attack!" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "Claptrap " << name << " attacks " << target << ", causing "
			  << attack_damage << " points of damage! "
			  << "(" << energy_points << " energy points left)" << std::endl;
}
void Claptrap::takeDamage(unsigned int amount) {
	if (hitpoints == 0) {
		std::cout << "Claptrap " << name << " has no hitpoints left and cannot take more damage!" << std::endl;
		return;
	}
	hitpoints -= amount;
	if (hitpoints < 0) hitpoints = 0;
	std::cout << "Claptrap " << name << " takes " << amount << " points of damage! "
			  << "(" << hitpoints << " hitpoints left)" << std::endl;
}
void Claptrap::beRepaired(unsigned int amount) {
	if (energy_points <= 0) {
		std::cout << "Claptrap " << name << " has no energy points left to repair!" << std::endl;
		return;
	}
	if (hitpoints <= 0) {
		std::cout << "Claptrap " << name << " has no hitpoints left and cannot be repaired!" << std::endl;
		return;
	}
	energy_points--;
	hitpoints += amount;
	std::cout << "Claptrap " << name << " is repaired by " << amount << " points! "
			  << "(" << hitpoints << " hitpoints, " << energy_points << " energy points left)" << std::endl;
}
