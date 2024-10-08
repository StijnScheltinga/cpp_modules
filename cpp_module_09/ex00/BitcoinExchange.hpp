#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::string iFile;
		std::string dbFile;

		std::ifstream	input;
		std::ifstream	database;

		std::map<std::string, float>	btcPrices;

		float	valueFloat;

		void	parseDatabase();
		void	parseInput();
		void	dateCheck(std::string date);
		void	valueCheck(std::string valueStr);
		void	calculatePrice(std::string date);
		void	printDatabase();
		unsigned int		daysInMonth(unsigned int month, unsigned int year);

		class CouldNotOpenFileException : public std::exception
		{
			public:
				const char* what() const noexcept {
					return "Could not open file!";
				}
		};

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

		class ValueOutOfRangeException : public std::exception
		{
			public:
				const char* what() const noexcept {
					return "Value out of range! => ";
				}
		};

		class DateTooEarlyException : public std::exception
		{
			public:
				const char* what() const noexcept {
					return "Date too early! must be higher or equal to 2009-01-02 => ";
				}
		};
	public:
		BitcoinExchange(const std::string& iFileIn, const std::string& dbFileIn);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		void	calculateValues();
};


#endif