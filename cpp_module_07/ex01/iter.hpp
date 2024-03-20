#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> 
void	iter(T* array, int length, void(*func)(T&))
{
	for (int i = 0; i != length; i++)
		func(array[i]);
}

template <typename T>
void	print(T& item)
{
	std::cout << item << std::endl;
}

#endif