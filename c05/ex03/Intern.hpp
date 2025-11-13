#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;
class Intern {
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();
		AForm *makeForm(const std::string &formName, const std::string &target);
};
#endif