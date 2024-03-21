#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int> vec1 = {1, 2, 3, 4};

	std::cout << ::easyfind(vec1, 3) << std::endl;
}