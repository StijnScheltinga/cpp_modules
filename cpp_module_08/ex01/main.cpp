#include "Span.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	// try
	// {
	// 	Span	vec(5);

	// 	vec.addNumber(11);
	// 	vec.addNumber(-100);
	// 	vec.addNumber(20);
	// 	vec.addNumber(50);
	// 	vec.addNumber(40);
	// 	// vec.addNumber(100);
		
	// 	std::cout << "index 2: " << vec[2] << std::endl;

	// 	std::cout << "longest span: " << vec.longestSpan() << std::endl;
	// 	std::cout << "shortest span: " << vec.shortestSpan() << std::endl;

	// 	std::cout << "this should throw an exception: " << vec[-1] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << '\n';
	// }

	// try
	// {
	// 	Span	vec2(10000);

	// 	for (int i = 0; i != 10000; i++)
	// 		vec2.addNumber(i * 15 % 100000);
		
	// 	std::cout << "longest span: " << vec2.longestSpan() << std::endl;
	// 	std::cout << "shortest span: " << vec2.shortestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << '\n';
	// }
	
	//adding numbers using a range of iterators

	Span			span(10);

	span.addNumber(1);
	span.addNumber(2);

	std::list<int>	intList(10);
	intList.push_back(3);
	intList.push_back(4);
	intList.push_back(5);
	intList.push_back(6);

	try
	{
		span.addNumber(intList.begin(), intList.end());
		span.printSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "Range of iterators exceeding max _N" << '\n';
	}
	
}