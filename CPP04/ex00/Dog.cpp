#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << GREEN << "Derived Dog: [" << this->type << "] created" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << GREEN << "Derived Dog [" << this->type << "] copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog::Dog::~Dog(void)
{
	std::cout << GREEN << "Derived Dog: [" << this->type << "] destroyed" << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << GREEN << "Derived Dog: [" << this->type << "] copy assignment called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}
