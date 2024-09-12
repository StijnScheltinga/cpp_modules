#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include <algorithm>

class PmergeMe
{
	public:
		class Vec
		{
			private:
				std::vector<unsigned int>							_input;
				std::vector<std::pair<unsigned int, unsigned int>>	pairsVector;
				std::vector<unsigned int>							main;
				std::vector<unsigned int>							pend;
				std::vector<unsigned int>							insertionOrder;
				std::vector<unsigned int>							mainPos;
				std::vector<unsigned int>							jacobsthalGroupSize;
				bool												leftOver;

				void	createPairs(std::vector<unsigned int>& input);
				void	mergeSort(std::vector<std::pair<unsigned int, unsigned int>>& pairsVec, unsigned int begin, unsigned int end);
				void	merge(std::vector<std::pair<unsigned int, unsigned int>>& pairsVec, unsigned int begin, unsigned int mid, unsigned int end);
				void	insert();
				void	jacobsthalSequence(unsigned int pendN);
				void	generateJacobsthalGroupSize();
				void	printPairs();
			public:
				Vec();
				~Vec();
				std::vector<unsigned int>	mergeInsertionSort(std::vector<unsigned int> input);
		};

		class Deque
		{
			private:
				std::deque<unsigned int>							_input;
				std::deque<std::pair<unsigned int, unsigned int>>	pairsDeque;
				std::deque<unsigned int>							main;
				std::deque<unsigned int>							pend;
				std::deque<unsigned int>							insertionOrder;
				std::deque<unsigned int>							mainPos;
				std::deque<unsigned int>							jacobsthalGroupSize;
				bool												leftOver;

				void	createPairs(std::deque<unsigned int>& input);
				void	mergeSort(std::deque<std::pair<unsigned int, unsigned int>>& pairsDeque, unsigned int begin, unsigned int end);
				void	merge(std::deque<std::pair<unsigned int, unsigned int>>& pairsDeque, unsigned int begin, unsigned int mid, unsigned int end);
				void	insert();
				void	jacobsthalSequence(unsigned int pendN);
				void	generateJacobsthalGroupSize();
				void	printPairs();
			public:
				Deque();
				~Deque();
				std::deque<unsigned int>	mergeInsertionSort(std::deque<unsigned int> input);
		};
};
