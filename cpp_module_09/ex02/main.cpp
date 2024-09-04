//creating a ford johnson sort algorithm first
#include <vector>
#include <iostream>
#include <utility>

template <typename T>
void	printContainer(const T& container)
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << ", ";
	std::cout << '\n';
}

//assumes vec is at least 2 big
std::vector<int>	fordJohnson(std::vector<int> vec)
{
	std::vector<std::pair<int, int>>	pairs;

	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.emplace_back(vec[i + 1], vec[i]);
		else
			pairs.emplace_back(vec[i], vec[i + 1]);
	}
	
	std::vector<int>	main;
	std::vector<int>	pend;

	for (size_t i = 0; i != pairs.size(); i++)
	{
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	if (vec.size() % 2 != 0)
		int leftOver = vec.back();
	
	return 
	
}

int	main()
{
	std::vector<int> vec = {1, 5, 2, 4, 10, 6, 8, 3, 7, 9, 11};
	std::cout << "unsorted vector: ";
	printContainer(vec);
	fordJohnson(vec);
	std::cout << "sorted vector: ";
	printContainer(vec);
}
