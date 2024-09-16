#include "RPN.hpp"

RPN::RPN(const std::string& inputStr) : input(inputStr) {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this == &other)
		return *this;
	this->input = other.input;
	this->stack = other.stack;
	return *this;
}

int	RPN::parseInput()
{
	if (input.size() == 0)
		return 1;
	std::istringstream	sstream(input);
	std::string			character;
	std::string			allowedChars = "+-/*";
	while (getline(sstream, character, ' '))
	{
		if (character.size() > 1)
			return 1;
		else if (character.size() == 0)
			continue ;
		
		if (std::isdigit(character[0]))
			stack.push(character[0] - '0');
		else if (allowedChars.find(character) != std::string::npos)
		{
			if (calculateTop(character[0]))
				return 1;
		}
		else
			return 1;
	}
	if (stack.size() != 1)
		return 1;
	else
		std::cout << stack.top() << std::endl;
	return 0;
}

int	RPN::calculateTop(char sign)
{
	if (stack.size() < 2)
		return 1;

	long long b = stack.top();
	stack.pop();
	long long a = stack.top();
	stack.pop();

	// std::cout << "a: " << a << '\n';
	// std::cout << "b: " << b << '\n';
	// std::cout << "sign: " << sign << '\n';

	long long result = jumpTable(a, b, sign);
	if (result > (long long)std::numeric_limits<int>::max() || result < (long long)std::numeric_limits<int>::min())
			return 1;
	
	// std::cout << "result: " << result << '\n';

	stack.push(result);
	return 0;
}

long long	RPN::jumpTable(long long a, long long b, char sign)
{
	if (sign == '-')
		return a - b;
	if (sign == '+')
		return a + b;
	if (sign == '*')
		return a * b;
	if (sign == '/')
		return a / b;
	return 0;
}