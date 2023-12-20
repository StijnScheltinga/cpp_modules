#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    float   test = 7.231;
    Fixed   b(10.5f);
    Fixed   c(1349.75f);

    b = (c / b);
    std::cout << b << std::endl;
    std::cout << b.toFloat() << std::endl;
    std::cout << test << std::endl;

}