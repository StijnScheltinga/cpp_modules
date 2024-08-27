#include <iostream>
#include <sstream>
#include <cctype>
#include <queue>

int	parseInput(const std::string& input, std::queue<char>& queue)
{
	std::istringstream	sstream(input);
	std::string			character;
	std::string			allowedChars = "+-/*";
	bool				isNumber = true;
	size_t				pos = 1;
	while (getline(sstream, character, ' '))
	{
		if (character.size() > 1)
			return 1;
		else if (character.size() == 0)
			continue ;

		//determines wether the char should be a number or a sign
		if (pos == 1 || pos % 2 == 0)
			isNumber = true;
		else
			isNumber = false;
		
		if (isNumber && std::isdigit(character[0]))
			queue.push(character[0]);
		else if (!isNumber && allowedChars.find(character) != std::string::npos)
			queue.push(character[0]);
		else
			return 1;
		pos++;
	}
	if (std::isdigit(queue.back()))
		return 1;
	return 0;
}

long long	jumpTable(long long a, long long b, char sign)
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

int	calculateOutput(std::queue<char>& queue)
{
	long long 		a;
	long long		b;
	char		sign;
	long long 	result = 0;
	a = queue.front() - '0';
		queue.pop();
	while (queue.size() != 0)
	{
		b = queue.front() - '0';
		queue.pop();
		sign = queue.front();
		queue.pop();
		std::cout << "a: " << a << '\n';
		std::cout << "b: " << b << '\n';
		std::cout << "sign: " << sign << '\n';
		result = jumpTable(a, b, sign);
		std::cout << "result: " << result << '\n';	
		a = result;
	}
	std::cout << result << '\n';
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string	input(argv[1]);
	std::queue<char>	queue;
	if (input.size() == 0 || parseInput(input, queue))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	if (calculateOutput(queue))
	{
		std::cout << "Over limit of type: long" << std::endl;
		return 1;
	}
	return 0;
}