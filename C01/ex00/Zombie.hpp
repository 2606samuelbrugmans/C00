#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string n);  // constructor declaration
    void announce(void);    // method declaration
	~Zombie();               // destructor (declaration)
};


void randomChump(std ::string name);
Zombie *newZombie(std::string name);

#endif
