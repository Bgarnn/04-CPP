#include "PhoneBook.hpp"

int main (void)
{
	std::string input_str;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter command: ";
		if(!(std::getline(std::cin, input_str)))
			break;
		else if(!input_str.compare("ADD"))
			phonebook.do_add();
		else if(!input_str.compare("SEARCH"))
			phonebook.do_search();
		else if(!input_str.compare("EXIT"))
			return(0);
		else
			std::cout << ">> Command not found <<" << '\n';
	}
	std::cout << '\n';
	return(0);
}