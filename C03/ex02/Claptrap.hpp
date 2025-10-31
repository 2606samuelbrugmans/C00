#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class Claptrap {
  protected:
	std::string name;
	int hitpoints;
	int energy_points;
	int attack_damage;

  public:
    Claptrap();
	Claptrap(std::string name);
	~Claptrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	Claptrap(Claptrap const &other);
	Claptrap &operator=(Claptrap const &other);

};


#endif