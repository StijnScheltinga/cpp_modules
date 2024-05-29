#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int>	a = Array<int>(10);
	try
	{
		std::cout << "size a: " << a.size() << std::endl;
		a[5] = 15;
		std::cout << a[5] << std::endl;
		std::cout << a[9] << std::endl;
		std::cout << a[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<double>	b = Array<double>(0);

	Array<double>	c = Array<double>(20);
	try
	{
		std::cout << "size c: " << a.size() << std::endl;
		c[1] = 1.1;
		std::cout << c[1] << std::endl;
		c[8] = 6.124;
		std::cout << c[8] << std::endl;
		std::cout << c[0] << std::endl;
		c[20] = 10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}