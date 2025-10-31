#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP
#include "Claptrap.hpp"

class Flagtrap : public Claptrap {
  private:
	
  public:
	Flagtrap(std::string name);
	~Flagtrap();
	void highFivesGuys();
	void attack(const std::string &target); // Override attack method
};

#endif
