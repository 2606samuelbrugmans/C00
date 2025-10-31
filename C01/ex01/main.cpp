#include "Zombie.hpp"

int main() {
	int n = 3;


	Zombie* horde = zombieHorde(n, "Steves");


	for ( *horde; horde; *horde++)
	{
		(*horde).announce();

	}
	delete[] horde;


	return 0;
}