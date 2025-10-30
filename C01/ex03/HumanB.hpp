#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"
class humanB
{
	private:
		std::string name;
		Weapon  *club;
	public:
		humanB(std::string n);
		~humanB();
		void    attack();
		void    setWeapon(Weapon &w);
};
#endif