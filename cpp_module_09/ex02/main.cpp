#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

#include "PmergeMe.hpp"

template <typename T>
void	printContainer(const T& container)
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << ", ";
	std::cout << '\n';
}

template <typename T>
bool	isSorted(const T& container)
{
	for (auto it = container.begin(); it != container.end(); it++)
	{
		if (it + 1 != container.end() && *it > *(it + 1))
			return false;
	}
	return true;
}

int	parseInput(std::vector<unsigned int>& input, int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "No input given" << std::endl;
		return 1;
	}
	if (argc > 100001)
	{
		std::cout << "PmergeMe can take a maximum of 100000 arguments" << std::endl;
		return 1;
	}

	unsigned long val;
	for (int i = 1; i != argc; i++)
	{
		if (argv[i][0] == '-')
		{
			std::cout << "Negative numbers are not allowed" << std::endl;
			return 1;
		}

		try
		{
			val = std::stoul(argv[i], nullptr, 10);
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "Invalid argument" << '\n';
			return 1;
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "Argument out of range" << '\n';
			return 1;
		}

		if (val > (unsigned long)std::numeric_limits<unsigned int>::max())
		{
			std::cout << "Argument out of range" << '\n';
			return 1;
		}
		
		if (std::find(input.begin(), input.end(), val) == input.end())
			input.push_back((unsigned int)val);
		else
		{
			std::cout << "No Duplicates are allowed" << '\n';
			return 1;
		}
	}
	return 0;
}


int	main(int argc, char **argv)
{
	std::vector<unsigned int>	input;
	std::vector<unsigned int>	output;
	PmergeMe::Vec				vec;

	if (parseInput(input, argc, argv))
		return 1;
	
	output = vec.mergeInsertionSort(input);

	if (isSorted(output))
		std::cout << "sorted\n";
	else
		std::cout << "not sorted\n";
}