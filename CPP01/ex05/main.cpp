#include "Harl.hpp"

int main (void)
{
	Harl message;

	std::cout << "\"DEBUG\" level   : ";
	message.complain("DEBUG");

	std::cout << "\"INFO\" level    : ";
	message.complain("INFO");

	std::cout << "\"WARNING\" level : ";
	message.complain("WARNING");

	std::cout << "\"ERROR\" level   : ";
	message.complain("ERROR");

	return(0);
}