#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
// Forward declaration to avoid circular include: Bureaucrat is defined in Bureaucrat.hpp
class Bureaucrat;

std::ostream &operator<<(std::ostream &out, const std::exception &e);

class AForm {
	private:
		const std::string name;
		bool is_signed;
		const unsigned int to_sign;
		const unsigned int to_execute;


	public:
		AForm();
		AForm(std::string const name, unsigned int to_sign, unsigned int to_execute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm();
		virtual void execute(Bureaucrat const &executor) const = 0;
		void beSigned(Bureaucrat &bureaucrat);
		const std::string getName() const;
		bool getIsSigned() const;
		unsigned int getToSign() const;
		unsigned int getToExecute() const;
		int ErrorHandling(int grade);

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};

		// Exception for unsignable forms at construction
		class UnsignableException : public std::exception {
			private:
				std::string msg;
			public:
				UnsignableException(const std::string &m);
				virtual ~UnsignableException() throw();
				virtual const char* what() const throw();
			};

		class FormNotSignedException : public std::exception {
			public:
				FormNotSignedException();
				virtual ~FormNotSignedException() throw();
				virtual const char* what() const throw();
			};
		class GradeTooLowToExecute : public std::exception {
			public:
				GradeTooLowToExecute();
				virtual ~GradeTooLowToExecute() throw();
				virtual const char* what() const throw();
		};



};
std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif