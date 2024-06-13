#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>
#include <string>
#include "utils.hpp"

class ScalarConverter
{
	private:
		ScalarConverter(void);
	public:
		ScalarConverter(ScalarConverter const &inst);
		ScalarConverter &operator=(ScalarConverter const &inst);
		~ScalarConverter(void);
		static void	convert(std::string const &argv);
};

#endif