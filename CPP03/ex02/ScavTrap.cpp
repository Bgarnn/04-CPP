#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_HitPoint = 100;
	this->_EnergeyPoint = 50;
	this->_AttackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << this->_Name << " is inheriting from ClapTrap" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoint = 100;
	this->_EnergeyPoint = 50;
	this->_AttackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << this->_Name << " is inheriting from ClapTrap" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << YELLOW << "ScavTrap " << this->_Name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << YELLOW << "ScavTrap "<< _Name << " has destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{
		this->_Name = obj._Name;
		this->_HitPoint = obj._HitPoint;
		this->_EnergeyPoint = obj._EnergeyPoint;
		this->_AttackDamage = obj._AttackDamage;
	}
	std::cout << "ScavTrap copy assignment called" << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << CYAN << "ScavTrap " << this->_Name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_EnergeyPoint > 0)
	{
		if (this->_HitPoint > 0)
		{
			std::cout << RED << "Scavtrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage  << " points of damage!" << std::endl;
			this->_EnergeyPoint -= 1;
		}
		else
			std::cout << RED << "Scavtrap " << this->_Name << " does not have enough HP to attack" << std::endl;
	}
	else
		std::cout << RED << "Scavtrap " << this->_Name << " does not have enough energy to attack" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}