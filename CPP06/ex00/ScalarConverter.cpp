#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){
	std::cout << "ScalarConverter Constructor created\n"; 
}

ScalarConverter::~ScalarConverter(void){
	std::cout << "ScalarConverter destroyed\n"; 
}

ScalarConverter::ScalarConverter(ScalarConverter const &inst){
	*this = inst;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &inst){
	(void) inst;
	return *this;
}

void	ScalarConverter::convert(std::string const &argv){
	if (argv == "nan" || argv == "nanf" )
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
	else if (argv == "+inf" || argv == "+inff" )
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
	else if (argv == "-inf" || argv == "-inff" )
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
	else if (argv.size() == 1 && std::isprint(argv[0]) && !std::isdigit(argv[0])){
		std::cout << "char: '" << argv[0] << "'\n";
		std::cout << "int: " << static_cast<int>(argv[0]) << '\n';
		std::cout << "float: " << static_cast<float>(argv[0]) << ".0f\n";
		std::cout << "double: " << static_cast<double>(argv[0]) << ".0\n";
	}
	else if (isInt(argv) == true || isFloat(argv) == true || isDouble(argv) == true)
		printAll(argv);
	else
		std::cout << "incorrect type\n";
}