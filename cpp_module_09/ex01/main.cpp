#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string	input(argv[1]);

	RPN	rpn(input);
	if (rpn.parseInput())
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}