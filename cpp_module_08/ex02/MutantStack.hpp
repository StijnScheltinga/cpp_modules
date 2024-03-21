#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack
{
	private:
		std::stack<T>	stack;
	public:
		MutantStack() {};
		~MutantStack() {};
		
};


#endif