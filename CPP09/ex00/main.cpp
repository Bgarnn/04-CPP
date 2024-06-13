#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << RED << "Error: could not open file." << std::endl << DEFAULT;
		return EXIT_FAILURE;
	}
	else if (argc != 2){
		std::cout << RED << "Error: incorrect agument." << std::endl << DEFAULT;
		return EXIT_FAILURE;
	}
	BitcoinExchange btc;
	btc.trade(argv[1]);
	return EXIT_SUCCESS;
}