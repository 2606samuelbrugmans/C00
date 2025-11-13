#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat a("Samuel", 55);
		std::cout << a << std::endl;
		Form f("tuertoutlemonde", 1, 100);
		std::cout << f << std::endl;
		f.beSigned(a);
		std::cout << f << std::endl;

	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Sam", 155);
		std::cout << b << std::endl;
		Form r("tuertoutlemonde", 30, 100);
		std::cout << r << std::endl;
		r.beSigned(b);
		std::cout << r << std::endl;

	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}
		try {
		Bureaucrat c("Big meower", 1);
		std::cout << c << std::endl;
		Form t("hugs", 1, 1);
		std::cout << t << std::endl;
		t.beSigned(c);
		std::cout << t << std::endl;

	} catch (std::exception & e) {
		std::cerr  << e.what() << std::endl;
	}


	return (0);
}