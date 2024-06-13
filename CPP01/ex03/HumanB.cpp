#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{}

HumanB::~HumanB(void)
{}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}


void	HumanB::attack(void)
{
	if (this->_weapon != NULL && !this->_weapon->getType().empty())
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}