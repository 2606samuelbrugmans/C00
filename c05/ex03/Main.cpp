#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	try {
		Bureaucrat a("little meower", 149);
		std::cout << a << std::endl;
		RobotomyRequestForm f("robocop");
		std::cout << f << std::endl;
		f.beSigned(a);
		std::cout << f << std::endl;
		f.execute(a);
	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Sam", 5);
		std::cout << b << std::endl;
		ShrubberyCreationForm r("garden");
		std::cout << r << std::endl;
		r.beSigned(b);
		std::cout << r << std::endl;
		r.execute(b);

	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}
	try {
		Bureaucrat c("Big meower", 1);
		std::cout << c << std::endl;
		PresidentialPardonForm p("Little meower");
		std::cout << p << std::endl;
		p.beSigned(c);
		std::cout << p << std::endl;
		p.execute(c);

	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat d("Bureaucrat oliver cromwell", 1);
		std::cout << d << std::endl;
		std::cout << *rrf << std::endl;
		rrf->beSigned(d);
		std::cout << *rrf << std::endl;
		rrf->execute(d);
		delete rrf;
		std::cout << d << std::endl;
		PresidentialPardonForm q("Little meower");
		std::cout << q << std::endl;
		q.beSigned(d);
		std::cout << q << std::endl;
		q.execute(d);

	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}

	return (0);
}