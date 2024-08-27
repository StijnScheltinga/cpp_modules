#include <iostream>
#include <sstream>

int	parseInput(const std::string& input)
{
	std::istringstream	sstream(input);
	std::string			character;
	std::string			allowedChars = "0123456789+-/*";
	while (getline(sstream, character, ' '))
	{
		std::cout << "input delimited on spaces: |" << character << "|\n";
		if (character.size() > 1)
			return 1;
		else if (character.size() == 0)
			continue;
		size_t found = allowedChars.find(character);
		if (found == std::string::npos)
			return 1;
		
	}
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
	if (input.size() == 0 || parseInput(input))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	// fillArray()
	// calculate();
	return 0;
}