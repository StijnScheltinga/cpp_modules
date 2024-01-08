#include "Fixed.hpp"
#include <iostream>

void    exampleSubject(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
}

int main(void)
{
    Fixed   a(6.12435f);
    Fixed   b(10);

    std::cout << "a = " << a.toFloat() << std::endl;
    std::cout << "b = " << b.toFloat() << std::endl;

    if (a > b)
        std::cout << "a is bigger than b" << std::endl;
    if (a < b)
        std::cout << "a is smaller than b" << std::endl;
    if (a >= b)
        std::cout << "a is bigger than or equal to b" << std::endl;
    if (a <= b)
        std::cout << "a is smaller than or equal to b" << std::endl;
    if (a == b)
        std::cout << "a is equal to b" << std::endl;
    if (a != b)
        std::cout << "a is not equal to b" << std::endl;
    std::cout << "a + b is equal to: " << a + b << std::endl;
    std::cout << "a - b is equal to: " << a - b << std::endl;
    std::cout << "a * b is equal to: " << a * b << std::endl;
    std::cout << "a / b is equal to: " << a / b << std::endl;
    std::cout << "max of a and b is " << Fixed::max(a, b) << std::endl;
    std::cout << "min of a and b is " << Fixed::min(a, b) << std::endl;

    const Fixed a_const(6.234f);
    const Fixed b_const(10);

    std::cout << "max of const a and b is " << Fixed::max(a_const, b_const) << std::endl;
    std::cout << "min of const a and b is " << Fixed::min(a_const, b_const) << std::endl;
    exampleSubject();
    return (0);
}