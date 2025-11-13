#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, const std::exception &e);

class Form {
	private:
		const std::string name;
		bool is_signed;
		const unsigned int to_sign;
		const unsigned int to_execute;


	public:
		Form();
		Form(std::string const name, unsigned int to_sign, unsigned int to_execute);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();
		void beSigned(Bureaucrat &bureaucrat);
		const std::string getName() const;
		bool getIsSigned() const;
		unsigned int getToSign() const;
		unsigned int getToExecute() const;
		int ErrorHandling(int grade);
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException();
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};

		// Exception thrown when constructor grades make the form unsignable
		class UnsignableException : public std::exception {
			private:
				std::string msg;
			public:
				UnsignableException(const std::string &m);
				virtual ~UnsignableException() throw();
				virtual const char* what() const throw();
			};


};
std::ostream &operator<<(std::ostream &out, Form const &form);

#endif