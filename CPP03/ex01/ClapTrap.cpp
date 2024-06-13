#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("Unknown"), _HitPoint(10), _EnergeyPoint(10), _AttackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << _Name << " has created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoint(10), _EnergeyPoint(10), _AttackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << _Name << " has created" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << YELLOW << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->_Name = obj._Name;
		this->_HitPoint = obj._HitPoint;
		this->_EnergeyPoint = obj._EnergeyPoint;
		this->_AttackDamage = obj._AttackDamage;
	}
	std::cout << YELLOW << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << YELLOW << "ClapTrap "<< _Name << " has destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_EnergeyPoint > 0)
	{
		if (this->_HitPoint > 0)
		{
			std::cout << RED << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage  << " points of damage!" << std::endl;
			this->_EnergeyPoint -= 1;
		}
		else
			std::cout << RED << "ClapTrap " << this->_Name << " does not have enough HP to attack" << std::endl;
	}
	else
		std::cout << RED << "ClapTrap " << this->_Name << " does not have enough energy to attack" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoint > 0)
	{
		if (this->_HitPoint >= amount)
		{
			std::cout << BLUE << "ClapTrap " << this->_Name << " has taken " << amount << " damage" << std::endl;
			this->_HitPoint -= amount;
		}
		else
		{
			std::cout << BLUE << "ClapTrap " << this->_Name << " has taken " << amount << " damage" << std::endl;
			this->_HitPoint = 0;
		}
	}
	else
		std::cout << BLUE << "ClapTrap " << this->_Name << " can't take anymore damage, HP is 0" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergeyPoint > 0)
	{
		if (this->_HitPoint > 0)
		{
			std::cout << GREEN << "ClapTrap " << this->_Name << " has been repaired " << amount << std::endl;
			if (this->_HitPoint > UINT_MAX - amount)
				this->_HitPoint = UINT_MAX;
			else
				this->_HitPoint += amount;
			this->_EnergeyPoint -=1;
		}
		else
			std::cout << GREEN << "ClapTrap " << this->_Name << " does not have enough HP to repair" << std::endl;
	}
	else
		std::cout << GREEN << "ClapTrap " << this->_Name << " does not have enough energy to repair" << std::endl;
	std::cout << DEFAULT << "         --> " << this->_Name << ": " << "Hit point " << this->_HitPoint << ", Energy point " << this->_EnergeyPoint << std::endl;
}
