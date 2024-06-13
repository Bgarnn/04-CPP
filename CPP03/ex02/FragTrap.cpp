#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_HitPoint = 100;
	this->_EnergeyPoint = 100;
	this->_AttackDamage = 30;
	std::cout << YELLOW << "FragTrap " << this->_Name << " is inheriting from ClapTrap" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoint = 100;
	this->_EnergeyPoint = 100;
	this->_AttackDamage = 30;
	std::cout << YELLOW << "FragTrap " << this->_Name << " is inheriting from ClapTrap" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << YELLOW << "FragTrap " << this->_Name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << YELLOW << "FlagTrap " << _Name << " has detroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		this->_Name = obj._Name;
		this->_HitPoint = obj._HitPoint;
		this->_EnergeyPoint = obj._EnergeyPoint;
		this->_AttackDamage = obj._AttackDamage;
	}
	std::cout << YELLOW << "FragTrap copy assignment called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FlagTrap " << this->_Name << " highfive to everyone!!!" << std::endl;
}
