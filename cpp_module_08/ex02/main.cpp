#include "MutantStack.hpp"
#include <list>
#include <iostream>

void mStackIterable(void)
{
	MutantStack<int> mstack;
	MutantStack<int>::iterator	mstackit;

	mstack.push(2);
	mstack.push(5);
	mstack.push(10);

	for (mstackit = mstack.begin(); mstackit != mstack.end(); mstackit++)
		std::cout << "Printing value of mstack by dereferencing an iterator: " << *mstackit << '\n'; 
}

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::list<int> intList;

	intList.push_back(5);
	intList.push_back(17);

	std::cout << intList.back() << std::endl;

	intList.pop_back();

	std::cout << intList.size() << std::endl;

	intList.push_back(3);
	intList.push_back(5);
	intList.push_back(737);
	//[...]
	intList.push_back(0);

	std::list<int>::iterator it2 = intList.begin();
	std::list<int>::iterator ite2 = intList.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	mStackIterable();
	
	return 0;
}