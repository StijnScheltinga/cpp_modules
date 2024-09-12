#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <chrono>

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
	std::vector<unsigned int>	inputVec;
	std::vector<unsigned int>	outputVec;
	PmergeMe::Vec				vec;

	if (parseInput(inputVec, argc, argv))
		return 1;
	
	auto startVec = std::chrono::high_resolution_clock::now();
	outputVec = vec.mergeInsertionSort(inputVec);
	auto endVec = std::chrono::high_resolution_clock::now();

	auto durationVec = std::chrono::duration_cast<std::chrono::nanoseconds>(endVec - startVec).count();
	auto durationVecMicro = durationVec / 1000;
	auto durationVecNano = durationVec % 1000;


	std::deque<unsigned int>	inputDeque(inputVec.begin(), inputVec.end()); 
	std::deque<unsigned int>	outputDeque;
	PmergeMe::Deque				deque;

	auto startDeque = std::chrono::high_resolution_clock::now();
	outputDeque = deque.mergeInsertionSort(inputDeque);
	auto endDeque = std::chrono::high_resolution_clock::now();

	auto durationDeque = std::chrono::duration_cast<std::chrono::nanoseconds>(endDeque - startDeque).count();
	auto durationDequeMicro = durationDeque / 1000;
	auto durationDequeNano = durationDeque % 1000;

	if (!isSorted(outputDeque) || !isSorted(outputVec))
		return 1;

	std::cout << "before: ";
	printContainer(inputVec);
	std::cout << "after: ";
	printContainer(outputVec);
	std::cout << "Time to process a range of " << inputVec.size() << " elements with std::vector : " << durationVecMicro << '.' << durationVecNano << " us\n";
	std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque : " << durationDequeMicro << '.' << durationDequeNano << " us\n";
}