#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& ifile, const std::string& dbfile) 
{
	input.open(ifile);
	database.open(dbfile);
	if (!input.is_open() || !database.is_open())
		throw std::exception();
}

BitcoinExchange::~BitcoinExchange() 
{
	input.close();
	database.close();
};
