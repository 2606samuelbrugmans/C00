#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat a("Stéphanie", 42);
	std::cout << a << std::endl;
	try {
		Bureaucrat b("Bob", 0);
	} catch (std::exception & e) {
		std::cerr << "Error creating Bureaucrat Bob: " << e.what() << std::endl;
	}
	try {
		Bureaucrat c("Charlie", 151);
	} catch (std::exception & e) {
		std::cerr << "Error creating Bureaucrat Charlie: " << e.what() << std::endl;
	}
	try {
		Bureaucrat d("David", 1);
		std::cout << d << std::endl;
		d.IncrementGrade();
		std::cout << d << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Error incrementing David's grade: " << e.what() << std::endl;
	}
	try {
		Bureaucrat d("Nicolas", 5);
		std::cout << d << std::endl;
		d.IncrementGrade();
		std::cout << d << std::endl;

	} catch (std::exception & e) {
		std::cerr << "Error incrementing Nicolas's grade: " << e.what() << std::endl;
	}
	try {
		Bureaucrat d("Samuel", 150);
		std::cout << d << std::endl;
		d.DecrementGrade();
	} catch (std::exception & e) {
		std::cerr << "Error decrementing Samuel's grade: " << e.what() << std::endl;
	}
	try {
		Bureaucrat d("kind meower", 149);
		std::cout << d << std::endl;
		d.DecrementGrade();
		std::cout << d << std::endl;

	} catch (std::exception & e) {
		std::cerr << "Error decrementing kind meower's grade: " << e.what() << std::endl;
	}
	return (0);
}