#include "Scavetrap.hpp"

int main() {
	Scavetrap clap("CL4P-TP");
	Scavetrap clap2 = clap;
	Scavetrap clap3("Temp");

	clap3 = clap;
	clap3.guardGate();
	clap2.attack("AnotherTarget");
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