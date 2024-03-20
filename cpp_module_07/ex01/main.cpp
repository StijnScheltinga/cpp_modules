#include "iter.hpp"

int	main(void)
{
	int arr[] = {1, 5, 3, 10, 7};
	double arr2[] = {2.0, 5.5, 1.8};
	std::string arr3[] = {"Jan", "Piet", "Remco", "Wessel"};

	::iter(arr, 5, ::print);
	::iter(arr2, 3, ::print);
	::iter(arr3, 4, ::print);
}