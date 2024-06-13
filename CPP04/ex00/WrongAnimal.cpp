#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Undefined")
{
	std::cout << RED << "Base WrongAnimal: [" << this->type << "] created" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << RED << "Base WrongAnimal: [" << this->type << "] created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << RED << "Base WrongAnimal: [" << this->type << "] copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "Base WrongAnimal: [" << this->type << "] destroyed" << DEFAULT << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << RED << "Base WrongAnimal: [" << this->type << "] copy assignment called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
