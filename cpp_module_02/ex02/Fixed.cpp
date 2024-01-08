#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed( const int value )
{
    this->value = value << n_fractional_bits;
}

Fixed::Fixed( const float value )
{
    this->value = roundf(value * (1 << n_fractional_bits));
}

Fixed::Fixed(const Fixed& old_obj)
{
    this->value = old_obj.getRawBits();
}

void Fixed::operator=(const Fixed& old_obj)
{
    this->value = old_obj.getRawBits();
}

int Fixed::getRawBits( void ) const
{
    return (value);
}

void    Fixed::setRawBits( int const raw )
{
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
    return value > other.getRawBits();
}

bool Fixed::operator<( const Fixed& other ) const
{
    return value < other.getRawBits();
}

bool Fixed::operator<=( const Fixed& other ) const
{
    return value <= other.getRawBits();
}

bool Fixed::operator>=( const Fixed& other ) const
{
    return value >= other.getRawBits();
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return value == other.getRawBits();
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return value != other.getRawBits();
}

float	Fixed::operator+( const Fixed& other ) const
{
	return this->toFloat() + other.toFloat();
}

float	Fixed::operator-( const Fixed& other ) const
{
	return this->toFloat() - other.toFloat();
}

float	Fixed::operator*( const Fixed& other ) const
{
	return this->toFloat() * other.toFloat();
}

float	Fixed::operator/( const Fixed& other ) const
{
	return this->toFloat() / other.toFloat();
}

//pre increment
Fixed&  Fixed::operator++(void)
{
    value++;
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    value--;
    return (*this);
}

//post increment, dummy int
Fixed  Fixed::operator++(int)
{
    Fixed   temp;

    temp = *this;
    value++;
    return (temp);
}

Fixed  Fixed::operator--(int)
{
    Fixed   temp;

    temp = *this;
    value--;
    return (temp);
}

Fixed&   Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed&   Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed&   Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    else 
        return (b);
}

const Fixed&   Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}
