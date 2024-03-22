#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>

class BitcoinExchange
{
	private:
		std::ifstream	input;
		std::ifstream	database;
	public:
		BitcoinExchange(const std::string& iFile, const std::string& dbFile);
		~BitcoinExchange();
};

#endif