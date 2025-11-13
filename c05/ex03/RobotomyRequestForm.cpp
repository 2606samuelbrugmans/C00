#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw AForm::GradeTooLowException();

	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	int random_value = std::rand() % 2;
	std::cout << "Bzzzzzz... Vrrrrrrr... *drilling noises*" << std::endl;
	if (random_value == 0)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << target << "." << std::endl;
	
		
}