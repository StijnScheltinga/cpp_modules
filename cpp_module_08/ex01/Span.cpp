#include "Span.hpp"

Span::Span(unsigned int n) : _N(n) {}

Span::~Span() {}

Span::Span(const Span& copy) : _N(copy._N) {}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
		_N = copy._N;
	return *this;
}

void	Span::addNumber(int value)
{
	if (vec.size() < _N)
		vec.push_back(value);
	else
		throw std::exception();
}

int	Span::operator[](unsigned int index)
{
	if (index >= vec.size())
		throw std::exception();
	return vec[index];
}

int	Span::shortestSpan(void)
{
	if (vec.size() < 2)
		throw std::exception();
	std::vector<int>	vec2(vec);
	std::sort(vec2.begin(), vec2.end());
	int	min = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
	{
		if (it == vec2.begin())
			continue;
		if (*it - *(it - 1) < min)
			min = *it - *(it - 1);
	}
	return min;
}

int	Span::longestSpan(void)
{
	if (vec.size() < 2)
		throw std::exception();
	std::vector<int>::iterator	max = std::max_element(vec.begin(), vec.end());
	std::vector<int>::iterator	min = std::min_element(vec.begin(), vec.end());
	return (*max - *min);
}