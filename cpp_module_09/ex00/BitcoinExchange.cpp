#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& ifile, const std::string& dbfile) 
{
	input.open(ifile);
	database.open(dbfile);
	if (!input.is_open() || !database.is_open())
		throw std::exception();
	parseDatabase();
}

BitcoinExchange::~BitcoinExchange() 
{
	input.close();
	database.close();
};

void	BitcoinExchange::parseDatabase()
{
	std::string	line;
	std::string	date;
	while (getline(database, line))
	{
		date = line.substr(0, line.find_first_of(","));
	}
}