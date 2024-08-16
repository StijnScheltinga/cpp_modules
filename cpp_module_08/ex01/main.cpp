#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>

//throw an exception if user tries to add int above max amount
void	intOverflow(void)
{
	Span sp = Span(3);

	try
	{
		sp.addNumber(0);
		sp.addNumber(0);
		sp.addNumber(0);
		sp.addNumber(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " 4th int is too much" << '\n';
	}
}

//only zero or one number in span
void	noSpanPossible(void)
{
	Span sp = Span(10);

	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " no span because no number" << '\n';
	}
	try
	{
		sp.addNumber(200);
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " no span because one number" << '\n';
	}
}

void	randomNumbers(void)
{
	Span sp(20000);
	srand(time(0));
	for (int i = 0; i != 20000; i++)
		sp.addNumber(rand());

	std::cout << "longest span: " << sp.longestSpan() << '\n';
	std::cout << "shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "value of 10000th entry: " << sp[10000] << '\n';

	// run ./span | wc -l to verify all 15000 are stored
	// sp.printSpan();
}

void	fillWithIterators(void)
{
	Span sp(10);

	std::list<int>	intList;
	intList.push_back(50);
	intList.push_back(100);
	intList.push_back(200);

	try
	{
		sp.addNumber(intList.begin(), intList.end());
		sp.printSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " list of iterators bigger than N" << '\n';
	}
}

int	main(void)
{
	std::cout << "example from subject: " << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	intOverflow();
	noSpanPossible();
	randomNumbers();
	fillWithIterators();
}