#include "BitcoinExchange.hpp"
#include <iostream>

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
	std::string	exchangeRate;
	while (getline(database, line))
	{
		date = line.substr(0, line.find_first_of(","));
		if (date == "date")
			continue;
		exchangeRate = line.substr(line.find_first_of(",") + 1, std::string::npos);
		btcPrices[date] = stod(exchangeRate);
		printDatabase();
	}
}

void	BitcoinExchange::printDatabase()
{
		for (const auto& pair : btcPrices)
			std::cout << "date: " << pair.first << ", price: " << pair.second << '\n';
}