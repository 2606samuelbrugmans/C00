#include "zombie.hpp"

int main() {
	Zombie* zombie1 = newZombie("Steve");
	Zombie* zombie2 = newZombie("Jerry");

	zombie1->announce();

	delete zombie1; // Clean up dynamically allocated memory
	delete zombie2; // Clean up dynamically allocated memory

	randomChump("RandomZombie");

	return 0;
}