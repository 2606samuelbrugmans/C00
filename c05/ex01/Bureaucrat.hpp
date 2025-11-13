#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat {
	private:
	const std::string name;
	unsigned int grade;
	public:

	Bureaucrat();
	Bureaucrat(std::string const name, unsigned int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();
	std::string getName() const;
	unsigned int getGrade() const;
	unsigned int IncrementGrade();
	unsigned int DecrementGrade();
	void ErrorHandling(int grade);
		class GradeTooHighException : public std::exception {
			private:
				std::string msg;
			public:
				GradeTooHighException(const std::string msg);
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string msg;
			public:
				GradeTooLowException(const std::string msg);
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif