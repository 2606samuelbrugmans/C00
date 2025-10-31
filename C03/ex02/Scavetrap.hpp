#ifndef SCAVETRAP_HPP
#define SCAVETRAP_HPP

#include <iostream>
#include <string>
#include "Claptrap.hpp"
class Scavetrap : public Claptrap {
  private:

  public:
	Scavetrap(std::string name);
	~Scavetrap();
	void guardGate();
	void attack(const std::string &target); // Override attack method
};


#endif