#include "PmergeMe.hpp"

PmergeMe::Vec::Vec() {};

PmergeMe::Vec::~Vec() {};

PmergeMe::Vec::Vec(const Vec& other)
{
	*this = other;
}

PmergeMe::Vec&	PmergeMe::Vec::operator=(const Vec& other)
{
	if (this == &other)
		return *this;
	this->_input = other._input;
	this->pairsVector = other.pairsVector;
	this->main = other.main;
	this->pend = other.pend;
	this->insertionOrder = other.insertionOrder;
	this->jacobsthalGroupSize = other.jacobsthalGroupSize;
	this->leftOver = other.leftOver;
	return *this;
}

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
		endPos = insertionOrder[i] + itemsInserted;
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

PmergeMe::Deque::Deque() {}

PmergeMe::Deque::~Deque() {}

PmergeMe::Deque::Deque(const Deque& other)
{
	*this = other;
}

PmergeMe::Deque&	PmergeMe::Deque::operator=(const Deque& other)
{
	if (this == &other)
		return *this;
	this->_input = other._input;
	this->pairsDeque = other.pairsDeque;
	this->main = other.main;
	this->pend = other.pend;
	this->insertionOrder = other.insertionOrder;
	this->jacobsthalGroupSize = other.jacobsthalGroupSize;
	this->leftOver = other.leftOver;
	return *this;
}

std::deque<unsigned int>	PmergeMe::Deque::mergeInsertionSort(std::deque<unsigned int> input)
{
	if (input.size() < 2)
		return input;

	_input = input;
	createPairs(input);
	mergeSort(pairsDeque, 0, pairsDeque.size() - 1);
	insert();
	return main;
}

void	PmergeMe::Deque::generateJacobsthalGroupSize()
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

void	PmergeMe::Deque::jacobsthalSequence(unsigned int pendN)
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

void	PmergeMe::Deque::insert()
{
	for (size_t i = 0; i != pairsDeque.size(); i++)
	{
		main.push_back(pairsDeque[i].first);
		pend.push_back(pairsDeque[i].second);
	}
	if (leftOver)
		pend.push_back(_input.back());

	main.push_front(pend[0]);
	pend.pop_front();

	if (pend.empty())
		return ;
	
	jacobsthalSequence(pend.size());

	unsigned int	val = 0;
	unsigned int	itemsInserted = 1;
	unsigned int	endPos = 0;
	for (size_t i = 0; i < pend.size(); i++)
	{
		val = pend[insertionOrder[i] - 1];
		endPos = insertionOrder[i] + itemsInserted;
		auto placeToInsert = std::upper_bound(main.begin(), main.begin() + endPos, val);
		main.insert(placeToInsert, val);
		itemsInserted++;
	}
}

void	PmergeMe::Deque::createPairs(std::deque<unsigned int>& input)
{
	for (size_t i = 0; (i + 1) < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
			pairsDeque.emplace_back(input[i + 1], input[i]);
		else
			pairsDeque.emplace_back(input[i], input[i + 1]);
	}
	if (input.size() % 2 != 0)
		leftOver = true;
	else
		leftOver = false;
}

void	PmergeMe::Deque::merge(std::deque<std::pair<unsigned int, unsigned int>>& pairsDeque, unsigned int begin, unsigned int mid, unsigned int end)
{
	unsigned int leftN = mid - begin + 1;
	unsigned int rightN = end - mid;

	std::deque<std::pair<unsigned int, unsigned int>>	leftTemp(leftN);
	std::deque<std::pair<unsigned int, unsigned int>>	rightTemp(rightN);

	for (unsigned int i = 0; i < leftN; i++)
		leftTemp[i] = pairsDeque[begin + i];
	for (unsigned int j = 0; j < rightN; j++)
		rightTemp[j] = pairsDeque[mid + 1 + j];

	unsigned int leftI = 0, rightI = 0;
	unsigned int mainIndex = begin;

	while (leftI < leftN && rightI < rightN)
	{
		if (leftTemp[leftI] < rightTemp[rightI])
		{
			pairsDeque[mainIndex] = leftTemp[leftI];
			leftI++;
		}
		else
		{
			pairsDeque[mainIndex] = rightTemp[rightI];
			rightI++;
		}
		mainIndex++;
	}

	while(leftI < leftN)
	{
		pairsDeque[mainIndex] = leftTemp[leftI];
		mainIndex++;
		leftI++;
	}

	while(rightI < rightN)
	{
		pairsDeque[mainIndex] = rightTemp[rightI];
		mainIndex++;
		rightI++;
	}
}

void	PmergeMe::Deque::mergeSort(std::deque<std::pair<unsigned int, unsigned int>>& pairsDeque, unsigned int begin, unsigned int end)
{
	if (begin >= end)
		return;
	unsigned int	mid = (begin + end) / 2;
	mergeSort(pairsDeque, begin, mid);
	mergeSort(pairsDeque, mid + 1, end);
	merge(pairsDeque, begin, mid, end);
}