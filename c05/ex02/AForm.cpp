#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), is_signed(false), to_sign(150), to_execute(150)
{

}

AForm::AForm(AForm const &other) : name(other.name), is_signed(other.is_signed), to_sign(other.to_sign), to_execute(other.to_execute)
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
		// name and grade limits are const and cannot be assigned
	}
	return *this;
}

AForm::~AForm()
{

}
AForm::AForm(std::string const n, unsigned int sign, unsigned int execute)
	: name(n), is_signed(false), to_sign(sign), to_execute(execute)
{
	try {
		ErrorHandling(sign);
		ErrorHandling(execute);
	} catch (std::exception &e) {
		throw UnsignableException(name + std::string(": unsignable: ") + e.what());
	}
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->to_sign)
		this->is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

const std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return is_signed;
}

unsigned int AForm::getToSign() const
{
	return this->to_sign;
}
unsigned int AForm::getToExecute() const
{
	return this->to_execute;
}
int AForm::ErrorHandling(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else
		return 1;
}
AForm::GradeTooLowToExecute::~GradeTooLowToExecute() throw()
{
}
AForm::GradeTooLowToExecute::GradeTooLowToExecute()
{
}
AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}
AForm::GradeTooLowException::GradeTooLowException()
{
}
const char *AForm::GradeTooLowToExecute::what() const throw()
{
	return "Form isn't signed and can't be executed";

}
const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign Exception";
}
// UnsignableException implementation
AForm::UnsignableException::UnsignableException(const std::string &m) : msg(m) {}
AForm::UnsignableException::~UnsignableException() throw() {}
const char* AForm::UnsignableException::what() const throw() { return msg.c_str(); }
// Form not signed
AForm::FormNotSignedException::FormNotSignedException()
{
}
AForm::FormNotSignedException::~FormNotSignedException() throw()
{
}
const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}
// Generic stream operator for exceptions: print what()
std::ostream &operator<<(std::ostream &out, const std::exception &e)
{
	out << e.what();
	return out;
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {

	std::string signedStatus;
	if (form.getIsSigned())
		signedStatus = "true";
	else
		signedStatus = "false";
		
	out << "Form name: " << form.getName() << ", is signed: " << signedStatus
		<< ", grade required to sign: " << form.getToSign()
		<< ", grade required to execute: " << form.getToExecute();
	return out;
}
