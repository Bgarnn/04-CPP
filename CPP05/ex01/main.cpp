#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n---------------[Can signed & execute]---------------\n";
	try 
	{
		Bureaucrat	Kawin("Kawin", 1);
		Form		paper("paper", 4, 1);

		std::cout << Kawin << paper;
		Kawin.signForm(paper);
		std::cout << paper;
	} 
	catch (std::exception &e)
	{
		std::cerr << CYAN << e.what() << DEFAULT;
	}
	
	std::cout << "\n---------------[Cannot signed & execute]---------------\n";
	try
	{
		Bureaucrat	Kawin("Kawin", 2);
		Form		paper("paper", 1, 1);
		
		std::cout << Kawin << paper;
		Kawin.signForm(paper);
		std::cout << paper;
	}
	catch (std::exception &e)
	{
		std::cerr << CYAN << e.what() << DEFAULT;
	}
}