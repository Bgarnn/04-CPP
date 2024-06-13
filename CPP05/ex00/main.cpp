#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n---------------[Exception circumstance not found]---------------\n";
	try
	{
		Bureaucrat a;
		Bureaucrat b("Kawin", 149);
		Bureaucrat c = Bureaucrat("Karn", 2);
		
		b.increment();
		c.decrement();
		std::cout << a << b << c;
	}
	catch (std::exception &e)
	{
		std::cerr << CYAN << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n---------------[Exception circumstance found]---------------\n";
	std::cout << "\n-->[decrement: grade 150]\n";
	try
	{
		Bureaucrat d = Bureaucrat("Kawin", 150);
		d.decrement();
	}
	catch (std::exception &e)
	{
		std::cerr << CYAN << e.what() << DEFAULT << std::endl;
	}
	std::cout << "\n-->[increment: grade 1]\n";
	try 
	{
		Bureaucrat i = Bureaucrat("Karn", 1);
		i.increment();
	}
	catch (std::exception &e)
	{
		std::cerr << CYAN << e.what() << DEFAULT << std::endl;
	}
}