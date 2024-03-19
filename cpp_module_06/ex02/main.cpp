#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base* generate(void)
{
	Base	*base;
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		base = new A();
	else if (i == 1)
		base = new B();
	else
		base = new C();
	return (base);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is of class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer is of class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer is of class C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "reference is of class A" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		B c = dynamic_cast<B&>(p);
		std::cout << "reference is of class B" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "reference is of class C" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
}

int	main(void)
{
	Base	*base = generate();

	identify(base);
	identify(*base);
}