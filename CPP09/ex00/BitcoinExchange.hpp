#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <fstream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <climits>

class BitcoinExchange{
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const& inst);
		BitcoinExchange &operator=(BitcoinExchange const& inst);
		void trade(std::string const& fileInput);

	private:
		std::map<std::size_t,float>	_mapData;
		std::string					_date, _value;
		int							_yearDataMin;

		std::size_t checkDate(std::string const& date_str, bool isData);
		float checkValue(std::string const& value_str, bool isData);
		void checkFile(std::ifstream &inputFile);
		std::size_t minusDate_oneDay(std::size_t const& dateCurr);
		bool isLeapYear(int const Year);
};

#endif
