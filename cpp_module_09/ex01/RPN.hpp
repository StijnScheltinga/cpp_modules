#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <sstream>
# include <iostream>
#include <limits>

class RPN
{
	private:
		std::string				input;
		std::stack<long long>	stack;

		long long	jumpTable(long long a, long long b, char sign);
	public:
		RPN(const std::string& input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		int	parseInput();
		int	calculateTop(char sign);
};


#endif