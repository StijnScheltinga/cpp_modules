#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "invalid argument" << std::endl;
		return 1;
	}
	try
	{
		std::string ifile(argv[1]);
		BitcoinExchange	exchange(ifile, "data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}