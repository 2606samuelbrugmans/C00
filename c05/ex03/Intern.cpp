#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}
Intern::Intern(Intern const &other)
{
	(void)other;
}
Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}
Intern::~Intern()
{
}
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			for (int j = 0; j < 3; j++) {
				if (j != i)
					delete forms[j];
			}
			return forms[i];
		}
	}
	std::cout << "Intern could not find the form: " << formName << std::endl;
	for (int j = 0; j < 3; j++) {
		delete forms[j];
	}
	return NULL;
}