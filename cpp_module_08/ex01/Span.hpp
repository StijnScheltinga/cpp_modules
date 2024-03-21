#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <limits>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	vec;
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		void	addNumber(int value);
		int		operator[](unsigned int index);
		int		shortestSpan(void);
		int		longestSpan(void);
};

#endif