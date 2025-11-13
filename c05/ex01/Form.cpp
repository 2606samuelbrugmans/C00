#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), to_sign(150), to_execute(150)
{

}

Form::Form(Form const &other) : name(other.name), is_signed(other.is_signed), to_sign(other.to_sign), to_execute(other.to_execute)
{
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
		// name and grade limits are const and cannot be reassigned
	}
	return *this;
}

Form::~Form()
{

}
Form::Form(std::string const n, unsigned int sign, unsigned int execute)
	: name(n), is_signed(false), to_sign(sign), to_execute(execute)
{
	try {
		ErrorHandling(sign);
		ErrorHandling(execute);
	} catch (std::exception &e) {
		// Re-throw a specific exception indicating this form cannot be signed
		throw UnsignableException(name + std::string(": unsignable: ") + e.what());
	}
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->to_sign)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
}

const std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return is_signed;
}

unsigned int Form::getToSign() const
{
	return this->to_sign;
}
unsigned int Form::getToExecute() const
{
	return this->to_execute;
}
int Form::ErrorHandling(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		return 1;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{
}
Form::GradeTooHighException::GradeTooHighException()
{

}
Form::GradeTooLowException::GradeTooLowException()
{
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high to sign Exception";
}
const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign Exception";
}
// UnsignableException implementation
Form::UnsignableException::UnsignableException(const std::string &m) : msg(m) {}
Form::UnsignableException::~UnsignableException() throw() {}
const char* Form::UnsignableException::what() const throw() { return msg.c_str(); }
// Generic stream operator for exceptions: print what()
std::ostream &operator<<(std::ostream &out, const std::exception &e)
{
	out << e.what();
	return out;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {

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


