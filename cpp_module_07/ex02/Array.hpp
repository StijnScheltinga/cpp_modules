#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		Array&	operator=(const Array& other);
		T&		operator[](unsigned int i);
		void	size(void);
};

# include "Array.tpp"

#endif