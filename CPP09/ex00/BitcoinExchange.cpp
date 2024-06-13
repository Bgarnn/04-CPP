#include "BitcoinExchange.hpp"

/*   Orthodox Canonical   */

BitcoinExchange::BitcoinExchange(void) {
	std::ifstream	file("data.csv");
	std::string		line;

	_yearDataMin = INT_MAX;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		std::cout << RED << "Error: incorrect data, first line." << std::endl << DEFAULT;
	while (std::getline(file, line)){
		try{
			if (line.find(',') != 10)
				throw std::invalid_argument("Error: incorrect data, pattern.");
			_mapData[checkDate(line.substr(0, line.find(',')), true)] = checkValue(line.substr(line.find(',') + 1), true);
		}catch(std::exception &e){
			std::cout << RED << e.what() << std::endl << DEFAULT;
			exit (EXIT_FAILURE);
		}
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& inst){
	*this = inst;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const& inst){
	if (this != &inst){
		this->_mapData = inst._mapData;
		this->_date = inst._date;
		this->_value = inst._value;
		this->_yearDataMin = inst._yearDataMin;
	}
	return *this;
}

/*   validate input   */

std::size_t	BitcoinExchange::checkDate(std::string const& date_str, bool isData){
	//check date pattern
	_date = date_str;
	if (date_str.length() != 10 || date_str.find_first_of('-') != 4 || date_str.find_last_of('-') != 7)
		throw std::invalid_argument("Error: incorrect date, pattern.");
	for (std::size_t i = 0; i< date_str.length(); i++){
		if (std::isdigit(date_str[i]) == 0 && date_str[i] != '-')
			throw std::invalid_argument("Error: incorrect date, non-digit.");
	}

	//remove - then turn to <size_t> ex. 20090102
	std::size_t	date_sizet;
	std::stringstream	stream_tmp(date_str.substr(0, 4) + date_str.substr(5, 2) + date_str.substr(8, 2));
	stream_tmp >> date_sizet;

	//store & validate <yesr> <month> <day>
	int	year = date_sizet / 10000; // ex. 20090102 / 10000 = 2009
	int month = (date_sizet % 10000) / 100; // ex. (20090102 % 10000) / 100 = 102 / 100 = 1
	int day = (date_sizet % 10000) % 100; // ex. (20090102 % 10000) % 100 = 102 % 100 = 2
	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw std::invalid_argument("Error: incorrect date, month/day.");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::invalid_argument("Error: incorrect date, day.");
	if (month == 2){
		if (day > (isLeapYear(year) ? 29 : 28))
			throw std::invalid_argument("Error: incorrect date, day.");
	}

	//init <minimum year> from <data file>
	if (isData == true){
		if(year < _yearDataMin)
			_yearDataMin = year;
	}
	return (date_sizet);
}

bool BitcoinExchange::isLeapYear(int const Year){
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
		return true;
	return false;
}

float BitcoinExchange::checkValue(std::string const& value_str, bool isData) {
	_value = value_str;
	if (value_str.empty())
		throw std::invalid_argument("Error: incorrect value, empty.");

	std::size_t firstDotPos = value_str.find('.');
	if (firstDotPos != std::string::npos) { //has dot
		if (firstDotPos == 0 || firstDotPos == value_str.length() - 1)
			throw std::invalid_argument("Error: incorrect value, dot at begin/end.");
		if (value_str.find('.', firstDotPos + 1) != std::string::npos)
			throw std::invalid_argument("Error: incorrect value, many dots.");
	}

	for (std::size_t i = (value_str[0] == '+' || value_str[0] == '-') ? 1 : 0; i < value_str.length(); i++) {
		if (std::isdigit(value_str[i]) == 0 && value_str[i] != '.' && value_str[i] != '+' && value_str[i] != '-') {
			throw std::invalid_argument("Error: incorrect value, non-digit.");
		}
	}

	float value_float;
	std::stringstream stream_tmp(value_str);
	stream_tmp >> value_float;

	if (isData == false) {
		if (value_float < 0)
			throw std::out_of_range("Error: not a positive number.");
		else if (value_float > 1000)
			throw std::out_of_range("Error: too large number.");
	}
	return value_float;
}

void BitcoinExchange::checkFile(std::ifstream &inputFile){
	if (inputFile.is_open() == false){
		std::cout << RED << "Error: could not open file." << std::endl << DEFAULT;
		exit (EXIT_FAILURE);
	}
	else if (inputFile.peek() == EOF){ //check that next character is EOF
		std::cout << RED << "Error: incorrect file, empty." << std::endl << DEFAULT;
		exit (EXIT_FAILURE);
	}
}

/*   calculate   */

void	BitcoinExchange::trade(std::string const& inputFile){
	std::ifstream	file(inputFile.c_str());
	std::string		line;

	checkFile(file);
	std::getline(file, line); //read first line
	if (line != "date | value") //validate first line
		std::cout << RED << "Error: incorrect input, first line." << std::endl << DEFAULT;
	while (std::getline(file, line)){ //read the rest of file
		std::map<std::size_t, float>	mapInput;
		//validate pattern
		if (line.find(" | ") != 10 || line.find_first_of(' ') != 10 || line.find_last_of(' ') != 12){
			std::cout << RED << "Error: bad input => " << line << std::endl << DEFAULT;
			continue ;
		}
		try{
			//extract line into <date> or <value> --> validate & store them
			mapInput[checkDate(line.substr(0, line.find_first_of(' ')), false)] = checkValue(line.substr(line.find_last_of(' ') + 1), false);
			//store input date
			std::size_t	dateTmp = mapInput.begin()->first; // first: key, second: value
			//find the exact <input date> in <data file>
			std::map<std::size_t,float>::iterator	it_data = _mapData.find(mapInput.begin()->first);
			while (it_data == _mapData.end()){ //did not find <date pointed by it_data> in <data file>
				//search for the <lower closest date>
				std::size_t	dateCurr = dateTmp;
				dateTmp = minusDate_oneDay(dateCurr); 
				it_data = _mapData.find(dateTmp);
				//if can find <curr date - 1> in <data file> --> <it_data> will point to that & NOT point to _mapData.end()--> will exit while loop
			}
			std::cout << _date << " => " << _value << " = " << mapInput.begin()->second * it_data->second << std::endl;
		}catch (std::exception &e){
			std::cout << RED << e.what() << std::endl << DEFAULT;
		}
	}
	file.close();
}

std::size_t BitcoinExchange::minusDate_oneDay(std::size_t const& dateCurr){
	int year = dateCurr / 10000;
	int month = (dateCurr % 10000) / 100;
	int day = (dateCurr % 10000) % 100;  
	int dayInMonth[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(year) == true)
		dayInMonth[2] = 29;
	day--;
	if (day == 0){
		month--;
		if (month == 0){
			month = 12;
			year--;
			if (year < _yearDataMin)
				throw std::out_of_range("Error: out of database range.");
		}
		day = dayInMonth[month];
	}
	return ((year * 10000) + (month * 100) + day);
}
