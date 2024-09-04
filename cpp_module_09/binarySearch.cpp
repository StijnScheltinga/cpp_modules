//binary search algorithm
#include <cmath>
#include <vector>
#include <iostream>

//binary search only works on sorted arrays
int	binarySearch(const std::vector<int>& vec, float left, float right, int value)
{	
	if (left > right)
		return -1;
	size_t	middle = floor((left + right) / 2);
	std::cout << "middle of vector: " << middle << '\n';
	if (vec[middle] > value)
		return binarySearch(vec, left, middle - 1, value);
	else if (vec[middle] < value)
		return binarySearch(vec, middle + 1, right, value);
	if (vec[middle] == value)
		return middle;
	return - 1;
}

int main(void)
{
	std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	std::cout << "is 10 in the vector?\n" << binarySearch(vec, 0, vec.size() - 1, 8) << std::endl;
	std::cout << "is 20 in the vector?\n" << binarySearch(vec, 0, vec.size() - 1, 20) << std::endl;
	std::cout << "is 3 in the vector?\n" << binarySearch(vec, 0, vec.size() - 1, 3) << std::endl;
}