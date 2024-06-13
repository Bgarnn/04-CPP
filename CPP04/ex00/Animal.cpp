#include "Animal.hpp"

Animal::Animal(void) : type("Undefined")
{
	std::cout << YELLOW << "Base Animal: [" << this->type << "] created" << std::endl;
}

Animal::Animal(const std::string &animal_type) : type(animal_type)
{
	std::cout << YELLOW << "Base Animal: [" << this->type << "] created" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << YELLOW << "Base Animal: [" << this->type << "] copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Animal::~Animal(void)
{
	std::cout << YELLOW <<  "Base Animal: [" << this->type << "] destroyed" << std::endl;
}

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << YELLOW << "Base Animal: [" << this->type << "] copy assignment called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
