#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "DEBUG MESSAGE" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "INFO MESSAGE" << std::endl;

}

void	Harl::warning( void )
{
	std::cout << "WARNING MESSAGE" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "ERROR MESSAGE" << std::endl;
}

void	Harl::complain( std::string level )
{
	func_arr		func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == cmd[i])
		{	
			(this->*func[i])();
			return ;
		}
	}
}
