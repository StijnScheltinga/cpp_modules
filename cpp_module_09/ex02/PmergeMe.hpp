#include <vector>
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

		class Deqeu
		{

		};
};
