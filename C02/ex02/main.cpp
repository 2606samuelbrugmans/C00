#include "fixed.hpp"

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	/*
	Fixed c(3);
	Fixed d(4);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;

	std::cout << std::boolalpha; // Print bools as true/false
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	Fixed e(0);
	std::cout << "e: " << e << std::endl;
	std::cout << "e / c: " << e / c << std::endl;
	std::cout << "d / e: " << d / e << std::endl;
	std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
	std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;
	std::cout << "Pre-increment c: " << ++c << std::endl;
	std::cout << "c after pre-increment: " << c << std::endl;
	std::cout << "Post-increment d: " << d++ << std::endl;
	std::cout << "d after post-increment: " << d << std::endl;
*/





	return 0;
}