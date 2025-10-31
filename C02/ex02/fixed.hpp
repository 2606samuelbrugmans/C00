#ifndef Fixed_HPP
#define Fixed_HPP
#include <iostream>
#include <cmath>
#include <ostream>

class Fixed
{
private:
	int                 fixed_point_value;
	static const int    fractional_bits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	float   toFloat(void) const;
	int     toInt(void) const;
	bool    operator>(const Fixed &other) const;
	bool    operator<(const Fixed &other) const;
	bool    operator>=(const Fixed &other) const;
	bool    operator<=(const Fixed &other) const;
	bool    operator==(const Fixed &other) const;
	bool    operator!=(const Fixed &other) const;
	Fixed   operator+(const Fixed &other) const;
	Fixed   operator-(const Fixed &other) const;
	Fixed   operator*(const Fixed &other) const;
	Fixed   operator/(const Fixed &other) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif

