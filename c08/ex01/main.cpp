#include "Span.hpp"

int main() {
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		// sp.addNumber(42);

	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}