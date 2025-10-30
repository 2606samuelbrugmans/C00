#include "Zombie.hpp"



Zombie::Zombie(std::string n) : name(n) {} // constructor
Zombie::~Zombie() { // destructor
        std::cout << name << " is destroyed!" << std::endl;
}


void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}