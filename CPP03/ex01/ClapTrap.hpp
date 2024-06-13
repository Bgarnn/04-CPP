#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define DEFAULT	"\033[0m"
# define YELLOW		"\033[33m"
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define GREEN		"\033[32m"
# define CYAN		"\033[36m"

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string		_Name;
		unsigned int	_HitPoint;
		unsigned int	_EnergeyPoint;
		unsigned int	_AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &obj);
		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &obj);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif