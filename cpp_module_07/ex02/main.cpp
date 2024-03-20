#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int>	a = Array<int>(10);
	try
	{
		std::cout << a[5] << std::endl;
		std::cout << a[9] << std::endl;
		std::cout << a[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}