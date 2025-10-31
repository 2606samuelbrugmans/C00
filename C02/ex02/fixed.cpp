#include "fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) {
}
Fixed::Fixed(const int n) : fixed_point_value(n << fractional_bits) {
}
Fixed::Fixed(const float f) : fixed_point_value(static_cast<int>(roundf(f * (1 << fractional_bits)))) {
}
Fixed::Fixed(const Fixed &other) : fixed_point_value(other.fixed_point_value) {
}
Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		fixed_point_value = other.fixed_point_value;
	}
	return *this;
}
Fixed::~Fixed() {
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
bool Fixed::operator>(const Fixed &other) const {
	return fixed_point_value > other.fixed_point_value;
}
bool Fixed::operator<(const Fixed &other) const {
	return fixed_point_value < other.fixed_point_value;
}
bool Fixed::operator>=(const Fixed &other) const {
	return fixed_point_value >= other.fixed_point_value;
}
bool Fixed::operator<=(const Fixed &other) const {
	return fixed_point_value <= other.fixed_point_value;
}
bool Fixed::operator==(const Fixed &other) const {
	return fixed_point_value == other.fixed_point_value;
}
bool Fixed::operator!=(const Fixed &other) const {
	return fixed_point_value != other.fixed_point_value;
}
Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const {
	if (other.fixed_point_value == 0)
	{
		std::cerr << "cannot divide by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}
Fixed &Fixed::operator++() {
	++fixed_point_value;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++fixed_point_value;
	return temp;
}
Fixed &Fixed::operator--() {
	--fixed_point_value;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--fixed_point_value;
	return temp;
}
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}