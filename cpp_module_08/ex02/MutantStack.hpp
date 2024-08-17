#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& src) {*this = src;};
		MutantStack& operator=(const MutantStack& src) 
		{
			if (*this != src)
				this->c = src.c;
			return (*this);
		}
		typedef typename std::deque<T>::iterator iterator;
		iterator	begin(void)
		{
			return this->c.begin();
		}
		iterator	end(void)
		{
			return this->c.end();
		}
};


#endif