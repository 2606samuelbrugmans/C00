#include "fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int n) : fixed_point_value(n << fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float f) : fixed_point_value(static_cast<int>(roundf(f * (1 << fractional_bits)))) {
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other) : fixed_point_value(other.fixed_point_value) {
	std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		fixed_point_value = other.fixed_point_value;
	}
	return *this;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const {
	return fixed_point_value;
}
void Fixed::setRawBits(int const raw) {
	fixed_point_value = raw;
}
float Fixed::toFloat(void) const {
	return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}
int Fixed::toInt(void) const {
	return fixed_point_value >> fractional_bits;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
