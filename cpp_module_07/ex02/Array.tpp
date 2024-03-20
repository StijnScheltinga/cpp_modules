#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : _arr(new T[0]), _n(0) {std::cout << "default constructor called\n";};

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _n(n) {std::cout << "array constructor called\n";};

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	this->_n = other._n;
	this->_arr = new T[this->_n];
	for (unsigned int i = 0; i != this->_n; i++)
		this->_arr[i] = other._arr[i];
	std::cout << "copy constructor called\n";
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
	std::cout << "deconstructor called\n";
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] this->_arr;
		this->_n = other._n;
		this->_arr = new T[this->_n];
		for (int i = 0; i != this->_n; i++)
			this->_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= _n || i < 0)
		throw std::exception();
	return _arr[i];
}

template <typename T>
void Array<T>::size(void)
{
	return _n;
}