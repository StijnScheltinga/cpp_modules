#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <limits>
# include <iostream>

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
		void	printSpan(void);

		template <typename it>
		void	addNumber(it begin, it end)
		{
			if (std::distance(begin, end) + vec.size() > _N)
				throw std::exception();
			vec.insert(vec.end(), begin, end);
		}
};

#endif