#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::ifstream	input;
		std::ifstream	database;

		std::map<std::string, double>	btcPrices;

		void	parseDatabase();
	public:
		BitcoinExchange(const std::string& iFile, const std::string& dbFile);
		~BitcoinExchange();
};

#endif