#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const n,unsigned int grade) : name(n), grade(grade)
{
	ErrorHandling(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}
unsigned int Bureaucrat::getGrade() const
{
	return this->grade;
}
std::string Bureaucrat::getName() const
{
	return this->name;
}
unsigned int Bureaucrat::IncrementGrade()
{
	ErrorHandling(grade - 1);
	return (grade - 1);
}
unsigned int Bureaucrat::DecrementGrade()
{
	ErrorHandling(grade + 1);
	return (grade + 1);
}
void Bureaucrat::ErrorHandling(int grade)
{
	if (grade < 1)
		throw GradeTooHighException(this->name);
	else if (grade > 150)
		throw GradeTooLowException(this->name);
	else
		this->grade = grade;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string who)
{
	msg = who + ": Grade too high Exception";
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{ 
	return msg.c_str(); }

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string who)
{
	msg = who + ": Grade too low Exception";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return msg.c_str(); }
// Destructors for nested exception types (match std::exception's throw() specification)
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
std::ostream &operator<<(std::ostream &out,const Bureaucrat &Bureaucrat) {
	out << Bureaucrat.getName() << ", bureaucrat grade :" << Bureaucrat.getGrade();
	return out;
}
