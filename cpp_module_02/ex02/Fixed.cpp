#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Deonstructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << n_fractional_bits;
}

Fixed::Fixed( const float value )
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << n_fractional_bits));
	std::cout << "Int value: " << this->value << std::endl;
}

Fixed::Fixed(const Fixed& old_obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = old_obj.getRawBits();
}

void Fixed::operator=(const Fixed& old_obj)
{
    std::cout << "Copy assignment overloader called" << std::endl;
    this->value = old_obj.getRawBits();
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float   Fixed::toFloat( void ) const
{
    return ((float)value / float(1 << n_fractional_bits)); 
}

int   Fixed::toInt( void ) const
{
    return (value / (1 << n_fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);    
}

bool Fixed::operator>( const Fixed& other ) const
{
    return value > other.value;
}

bool Fixed::operator<( const Fixed& other ) const
{
    return value < other.value;
}

bool Fixed::operator<=( const Fixed& other ) const
{
    return value <= other.value;
}

bool Fixed::operator>=( const Fixed& other ) const
{
    return value >= other.value;
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return value == other.value;
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return value != other.value;
}

float	Fixed::operator+( const Fixed& other ) const
{
	return value + other.value;
}

float	Fixed::operator-( const Fixed& other ) const
{
	return value - other.value;
}

float	Fixed::operator*( const Fixed& other ) const
{
	return value * other.value;
}

float	Fixed::operator/( const Fixed& other ) const
{
	std::cout << "Divide operator called" << std::endl;
	return value / other.value;
}