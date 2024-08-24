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
		btcPrices[date] = stof(exchangeRate);
	}
	// printDatabase();
	parseInput();
}

void	BitcoinExchange::parseInput()
{
	std::string	line;
	std::string	date;
	std::string	value;
	std::size_t	middlePos;

	while(getline(input, line))
	{
		middlePos = line.find_first_of("|");
		if (middlePos == std::string::npos)
		{
			std::cout << "middle is not found! => " << line << '\n';
			continue;
		}
		else if (line.size() < 3)
		{
			std::cout << "line is not properly formatted! => " << line << '\n';
			continue;
		}

		date = line.substr(0, middlePos - 1);
		if (date == "date")
			continue;
		value = line.substr(middlePos + 2, std::string::npos);

		try
		{
			dateCheck(date);
			valueCheck(value);
			calculatePrice(date);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << line << '\n';
		}
	}
}

void	BitcoinExchange::valueCheck(std::string valueStr)
{
	try
	{
		valueFloat = stof(valueStr);
	}
	catch(const std::exception& e)
	{
		throw ValueFormatException();
	}
	if (valueFloat < 0 || valueFloat > 1000)
		throw ValueOutOfRangeException();

}

void	BitcoinExchange::dateCheck(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::DateFormatException();
	for (std::size_t i = 0; i != date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			throw BitcoinExchange::DateFormatException();
	}
}

void	BitcoinExchange::calculatePrice(std::string date)
{
	std::map<std::string, float>::iterator	it;
	it = btcPrices.find(date);
	if (it == btcPrices.end())
	{
		it = btcPrices.lower_bound(date);
		if (it == btcPrices.begin())
			throw DateTooEarlyException();
		it--;
	}
	// std::cout << "input date: " << date << ", value: " << valueFloat << ", db date: " << (*it).first << ", db value: " << (*it).second << ", result: " << valueFloat * (*it).second << '\n';
	// std::cout << date << " => " << valueFloat << " * " << (*it).second << " = " << '\n';
	std::cout << date << " => " << valueFloat <<  " = " << valueFloat * (*it).second << '\n';
}

void	BitcoinExchange::printDatabase()
{
		for (const auto& pair : btcPrices)
			std::cout << "date: " << pair.first << ", price: " << pair.second << '\n';
}