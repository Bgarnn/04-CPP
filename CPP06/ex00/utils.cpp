#include "utils.hpp"

bool isInt(std::string const &argv){
	std::size_t j = 0;

	if (argv[j] == '+' || argv[j] == '-')
		j++;
	for (std::size_t i = j; i < argv.length(); i++){
		if (std::isdigit(argv[i]) == 0)
			return false;
	}
	return true;
}

bool isFloat(std::string const &argv){
	std::size_t j = 0;
	std::size_t dot_found = 0;
	
	if (argv.find ('.') == std::string::npos || argv.find ('.') == 0 || argv.find ('.') == argv.length() - 2 || argv.back() != 'f')
		return false;
	if (argv[j] == '+' || argv[j] == '-')
		j++;
	for (std::size_t i = j; i < argv.length() - 1; i++){
		if (argv[i] == '.')
			dot_found += 1;
		if ((std::isdigit(argv[i]) == 0 && argv[i] != '.') || dot_found > 1)
			return false;
	}
	return true;
}

bool isDouble(std::string const &argv){
	std::size_t j = 0;
	std::size_t dot_found = 0;
	
	if (argv.find ('.') == std::string::npos || argv.find ('.') == 0 || argv.find ('.') == argv.length() - 1)
		return false;
	if (argv[j] == '+' || argv[j] == '-')
		j++;
	for (std::size_t i = j; i < argv.length(); i++){
		if (argv[i] == '.')
			dot_found += 1;
		if ((std::isdigit(argv[i]) == 0 && argv[i] != '.') || dot_found > 1)
			return false;
	}
	return true;
}

static void printCharInt(std::string const &argv){
	char* endptr;
	long argvInt = std::strtol(argv.c_str(), &endptr, 10);
	if ((argvInt >= 32) && (argvInt < 127))
		std::cout << "char: '" << static_cast<char>(argvInt) << "'\n";
	else if ((argvInt >= 0) && (argvInt <= 255))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: impossible\n";
	if (argvInt > INT_MAX || argvInt < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << argvInt << "\n";
}

static void printFloat(std::string const &argv){
	float argvFloat = std::atof(argv.c_str());
	printCharInt(argv);
	if (argvFloat - static_cast<int>(argvFloat) == 0)
		std::cout << "float: " << argvFloat << ".0f\n";
	else if (std::isinf(argvFloat) && argvFloat > 0)
		std::cout << "float: +" << argvFloat << "f\n";
	else
		std::cout << "float: " << argvFloat << "f\n";
}

void printAll(std::string const &argv){
	char* endPtr;
	double argvDouble = std::strtod(argv.c_str(), &endPtr);
	printFloat(argv);
	if (argvDouble - static_cast<int>(argvDouble) == 0)
		std::cout << "double: " << argvDouble << ".0\n";
	else if (std::isinf(argvDouble) && argvDouble > 0)
		std::cout << "double: +" << argvDouble << "\n";
	else
		std::cout << "double: " << argvDouble << "\n";
}