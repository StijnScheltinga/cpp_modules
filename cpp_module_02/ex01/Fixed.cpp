#include "Fixed.hpp"

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
    this->value = value + ((2 ^ n_fractional_bits) - 1);
}

Fixed::Fixed( const float value )
{
    
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
