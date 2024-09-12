#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& ifile, const std::string& dbfile) 
{
	input.open(ifile);
	database.open(dbfile);
	if (!input.is_open() || !database.is_open())
		throw CouldNotOpenFileException();
	parseDatabase();
}

BitcoinExchange::~BitcoinExchange() 
{
	input.close();
	database.close();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;	
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;
	this->btcPrices = other.btcPrices;
	return *this;
}

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
			std::cout << "Bad input! => " << line << '\n';
			continue;
		}
		else if (line.size() < 3 || line[middlePos - 1] != ' ' || line[middlePos + 1] != ' ')
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
	//check if all dates are digits
	for (std::size_t i = 0; i != date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			throw BitcoinExchange::DateFormatException();
	}
	unsigned int	day = std::atoi((date.substr(8, 2)).c_str());
	unsigned int	month = std::atoi((date.substr(5, 2)).c_str());
	unsigned int	year = std::atoi((date.substr(0, 4)).c_str());

	if (month < 1 || month > 12 || year < 1)
		throw BitcoinExchange::DateFormatException();
	if (day < 1 || day > daysInMonth(month, year))
		throw BitcoinExchange::DateFormatException();
}

unsigned int	BitcoinExchange::daysInMonth(unsigned int month, unsigned int year)
{
	bool	isLeapYear = false;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		isLeapYear = true;
	unsigned int months31days[] = {1, 3, 5, 7, 8, 10, 12};
	unsigned int months30days[] = {4, 6, 9, 11};

	for (int i = 0; i < 7; i++)
		if (month == months31days[i])
			return 31;
	
	for (int i = 0; i < 4; i++)
		if (month == months30days[i])
			return 30;
	
	if (month == 2)
		return (isLeapYear) ? 29 : 28;
	
	return 0;
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

	std::cout << date << " => " << valueFloat <<  " = " << valueFloat * (*it).second << '\n';
}

void	BitcoinExchange::printDatabase()
{
		for (const auto& pair : btcPrices)
			std::cout << "date: " << pair.first << ", price: " << pair.second << '\n';
}