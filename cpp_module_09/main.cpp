//creating a ford johnson sort algorithm first
#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <limits>

const unsigned int jacobsthalGroupSize[] = {
	2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 0
};

template <typename T>
void	printContainer(const T& container)
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << ", ";
	std::cout << '\n';
}

std::vector<size_t>	Jacobsthal(size_t	pend_n)
{
	std::vector<size_t>	sequence;
	size_t				n = 0;
	size_t				groupIndex = 0;

	//if next group fits within the pending
	while (n < pend_n)
	{
		size_t previousJacobsthal = n;
		n += jacobsthalGroupSize[groupIndex++];
		if (n <= pend_n)
		{
			// fill in the order sequence in reverse from each jacobsthal number
			for (size_t order = n; order > previousJacobsthal; order--)
				sequence.push_back(order);
		}
		else
		{
			size_t diff = n - pend_n;
			//fill in the order sequence in reverse from each jacobsthal number - the difference
			for (size_t order = n - diff; order > previousJacobsthal; order--)
				sequence.push_back(order);
		}
	}
	std::cout << "order of insertion: ";
	printContainer(sequence);
	return sequence;
}

// void	insertPendIntoMain(std::vector<int>& main, std::vector<int>& pend)
// {
// 	//Use the jacobsthal sequence to determine which item from pend should be inserted.
// 	std::vector<size_t>	insertionOrder = Jacobsthal(pend.size());

// 	for (size_t i = 0; i < pend.size(); i++)
// 	{
// 		int value = pend[insertionOrder[i] - 1];
// 		std::cout << "value to insert: " << value << std::endl;
// 		//need to find main element for the pend val wanting to insert. Binary search upto but not including this value
// 		auto	second = main.begin() + ;
// 		auto	placeToInsert() = std::upper_bound(main.begin(), );
// 		main.insert(, val);
// 	}

std::vector<unsigned int>	getBinSearchGroups(void)
{
	std::vector<unsigned int>	binSearchGroups;
	long						powerOfTwo = 4; //for our implementation 2 is not necessary

	while (powerOfTwo < (long)std::numeric_limits<unsigned int>::max())
	{
		binSearchGroups.push_back((unsigned int)powerOfTwo - 1);
		powerOfTwo *= 2;
	}

	printContainer(binSearchGroups);

	return binSearchGroups;
}

std::vector<unsigned int>	fordJohnson(std::vector<unsigned int> input)
{
	std::vector<std::pair<unsigned int, unsigned int>>	pairs;

	if (input.size() <= 1)
		return input;

	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.emplace_back(input[i + 1], input[i]);
		else
			pairs.emplace_back(input[i], input[i + 1]);
	}
	
	std::vector<unsigned int>	main;
	std::vector<unsigned int>	pend;

	for (size_t i = 0; i != pairs.size(); i++)
	{
		main.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}

	if (input.size() % 2 != 0)
		pend.push_back(input.back());

	//recursivly split into main and pend chains
	main = fordJohnson(main);
	
	//then start inserting pend into main
		// insertPendIntoMain(main, pend);

	//first insert the first from pend before the first from main since it is known to be smaller
	main.insert(main.begin(), pend[0]);
	pend.erase(pend.begin());

	//if empty all elements are already inserted
	if (pend.empty())
		return main;

	//get the insertion order, to use the vector as an index -1 the values
	std::vector<size_t>	insertionOrder = Jacobsthal(pend.size());
	std::vector<unsigned int>	binSearchGroups = getBinSearchGroups();

	for (size_t i = 0; jacobsthalGroupSize[i] != 0; i++)
	{
		for (size_t	groupIndex = insertionOrder[i])

		
		int value = pend[insertionOrder[i] - 1];
		std::cout << "value to insert: " << value << std::endl;
		auto	placeToInsert() = std::upper_bound(main.begin(), main);
		main.insert(, val);
	}

	return main;
	
}

int	main()
{
	// std::vector<int> vec = {1, 5, 2, 4, 10, 6, 8, 3, 7, 9, 11};
	// std::cout << "unsorted vector: ";
	// printContainer(vec);
	// fordJohnson(vec);
	// std::cout << "sorted vector: ";
	// printContainer(vec);
	// Jacobsthal(1);
	binSearchGroups();
}
