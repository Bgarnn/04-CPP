#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect input\n";
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
	return EXIT_SUCCESS;
}