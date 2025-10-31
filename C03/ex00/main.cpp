#include "Claptrap.hpp"

int main() {
	Claptrap clap("CL4P-TP");

	clap.attack("Target1");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.takeDamage(8);
	clap.attack("Target2");
	clap.beRepaired(2);
	clap.takeDamage(10);
	clap.beRepaired(1);

	return 0;
}