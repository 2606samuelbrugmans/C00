#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"
class humanA
{
	private:
		std::string name;
		Weapon  *sword;
	public:
		humanA(std::string n, Weapon &w);
		~humanA();
		void    attack();
		void    setWeapon(Weapon &w);
};
#endif