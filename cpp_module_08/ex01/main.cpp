#include "Span.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Span	vec(5);

		vec.addNumber(11);
		vec.addNumber(-100);
		vec.addNumber(20);
		vec.addNumber(50);
		vec.addNumber(40);
		// vec.addNumber(100);
		
		std::cout << "index 2: " << vec[2] << std::endl;
		// std::cout << vec[5] << std::endl;

		std::cout << "longest span: " << vec.longestSpan() << std::endl;
		std::cout << "shortest span: " << vec.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Span	vec2(10000);

		for (int i = 0; i != 10000; i++)
			vec2.addNumber(i * 15 % 100000);
		
		std::cout << "longest span: " << vec2.longestSpan() << std::endl;
		std::cout << "shortest span: " << vec2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}