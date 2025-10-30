#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;
public:
	Zombie();               
    Zombie(std::string n);  
    void announce(void);
	void naming(std::string n);
	~Zombie();
};
Zombie *newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif
