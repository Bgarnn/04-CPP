#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED << "Error: invalid argument" << std::endl << DEFAULT;
		return EXIT_FAILURE;
	}

	try {
		RPN rpn;
		rpn.evaluate(argv[1]);
		return EXIT_SUCCESS;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << std::endl << DEFAULT;
		return EXIT_FAILURE;
	}
}
