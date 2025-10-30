#include "Zombie.hpp"


Zombie *newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	///zombie->announce();
	return zombie;
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
        return NULL;  // no zombies

    Zombie* horde = new Zombie[N]; // allocate array of N Zombies
	for (int i = 0; i < N; i++)
	{
		horde[i].naming(name);

	}
	return horde;
}