#include "PmergeMe.hpp"

PmergeMe::Vec::Vec() {};

PmergeMe::Vec::~Vec() {};

void	PmergeMe::Vec::printPairs()
{
	for (size_t i = 0; i != pairsVector.size(); i++)
		std::cout << "pair " << i << ": " << pairsVector[i].first << ", " << pairsVector[i].second << '\n';
}

template <typename T>
void	printContainer(const T& container)
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << ", ";
	std::cout << '\n';
}

std::vector<unsigned int>	PmergeMe::Vec::mergeInsertionSort(std::vector<unsigned int> input)
{
	if (input.size() < 2)
		return input;

	_input = input;
	createPairs(input);
	mergeSort(pairsVector, 0, pairsVector.size() - 1);
	insert();
	return main;
}

void	PmergeMe::Vec::generateJacobsthalGroupSize()
{
	jacobsthalGroupSize.push_back(2);
	jacobsthalGroupSize.push_back(2);

	unsigned int	groupSize = 0;
	unsigned int	groupTotal = 4;

	while (groupTotal < 200000)
	{
		auto it = jacobsthalGroupSize.end();
		groupSize = *(it - 1) + 2 * *(it - 2);
		jacobsthalGroupSize.push_back(groupSize);
		groupTotal += groupSize;
	}
}

void	PmergeMe::Vec::jacobsthalSequence(unsigned int pendN)
{
	size_t				n = 0;
	size_t				groupIndex = 0;

	generateJacobsthalGroupSize();

	//if next group fits within the pending
	while (n < pendN)
	{
		size_t previousJacobsthal = n;
		n += jacobsthalGroupSize[groupIndex++];
		if (n <= pendN)
		{
			// fill in the order sequence in reverse from each jacobsthal number
			for (size_t order = n; order > previousJacobsthal; order--)
				insertionOrder.push_back(order);
		}
		else
		{
			size_t diff = n - pendN;
			//fill in the order insertionOrder in reverse from each jacobsthal number - the difference
			for (size_t order = n - diff; order > previousJacobsthal; order--)
				insertionOrder.push_back(order);
		}
	}
}

void	PmergeMe::Vec::insert()
{
	for (size_t i = 0; i != pairsVector.size(); i++)
	{
		main.push_back(pairsVector[i].first);
		pend.push_back(pairsVector[i].second);
	}
	if (leftOver)
		pend.push_back(_input.back());

	main.insert(main.begin(), pend[0]);
	pend.erase(pend.begin());

	if (pend.empty())
		return ;
	
	jacobsthalSequence(pend.size());

	unsigned int	val = 0;
	unsigned int	itemsInserted = 1;
	unsigned int	endPos = 0;
	for (size_t i = 0; i < pend.size(); i++)
	{
		val = pend[insertionOrder[i] - 1];
		// std::cout << "value to insert: " << val << '\n';
		endPos = insertionOrder[i] + itemsInserted;
		// std::cout << "endpos: " << endPos << '\n';
		auto placeToInsert = std::upper_bound(main.begin(), main.begin() + endPos, val);
		main.insert(placeToInsert, val);
		itemsInserted++;
	}
}

void	PmergeMe::Vec::createPairs(std::vector<unsigned int>& input)
{
	for (size_t i = 0; (i + 1) < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
			pairsVector.emplace_back(input[i + 1], input[i]);
		else
			pairsVector.emplace_back(input[i], input[i + 1]);
	}
	if (input.size() % 2 != 0)
		leftOver = true;
	else
		leftOver = false;
}

void	PmergeMe::Vec::merge(std::vector<std::pair<unsigned int, unsigned int>>& pairsVec, unsigned int begin, unsigned int mid, unsigned int end)
{
	unsigned int leftN = mid - begin + 1;
	unsigned int rightN = end - mid;

	std::vector<std::pair<unsigned int, unsigned int>>	leftTemp(leftN);
	std::vector<std::pair<unsigned int, unsigned int>>	rightTemp(rightN);

	for (unsigned int i = 0; i < leftN; i++)
		leftTemp[i] = pairsVec[begin + i];
	for (unsigned int j = 0; j < rightN; j++)
		rightTemp[j] = pairsVec[mid + 1 + j];

	unsigned int leftI = 0, rightI = 0;
	unsigned int mainIndex = begin;

	while (leftI < leftN && rightI < rightN)
	{
		if (leftTemp[leftI] < rightTemp[rightI])
		{
			pairsVec[mainIndex] = leftTemp[leftI];
			leftI++;
		}
		else
		{
			pairsVec[mainIndex] = rightTemp[rightI];
			rightI++;
		}
		mainIndex++;
	}

	while(leftI < leftN)
	{
		pairsVec[mainIndex] = leftTemp[leftI];
		mainIndex++;
		leftI++;
	}

	while(rightI < rightN)
	{
		pairsVec[mainIndex] = rightTemp[rightI];
		mainIndex++;
		rightI++;
	}
}

void	PmergeMe::Vec::mergeSort(std::vector<std::pair<unsigned int, unsigned int>>& pairsVec, unsigned int begin, unsigned int end)
{
	if (begin >= end)
		return;
	unsigned int	mid = (begin + end) / 2;
	mergeSort(pairsVec, begin, mid);
	mergeSort(pairsVec, mid + 1, end);
	merge(pairsVec, begin, mid, end);
}