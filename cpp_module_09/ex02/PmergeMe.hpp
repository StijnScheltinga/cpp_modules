#include <vector>
#include <iostream>
#include <utility>

const unsigned int jacobsthalGroupSize[] = {
		2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 0};

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
				bool												leftOver;

				void	createPairs(std::vector<unsigned int>& input);
				void	mergeSort(std::vector<std::pair<unsigned int, unsigned int>>& pairsVec, unsigned int begin, unsigned int end);
				void	merge(std::vector<std::pair<unsigned int, unsigned int>>& pairsVec, unsigned int begin, unsigned int mid, unsigned int end);
				void	insert();
				void	jacobsthalSequence(unsigned int pendN);
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
