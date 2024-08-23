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
		void	parseInput();
		void	dateCheck(std::string date);
		void	valueCheck(std::string value);
		void	printDatabase();

		class DateFormatException : public std::exception
		{
			public:
				const char* what() const noexcept {
					return "Incorrect date format! => ";
				}
		};
		
		class ValueFormatException : public std::exception
		{
			public:
				const char* what() const noexcept {
					return "Incorrect value format! => ";
				}
		};
	public:
		BitcoinExchange(const std::string& iFile, const std::string& dbFile);
		~BitcoinExchange();
};


#endif