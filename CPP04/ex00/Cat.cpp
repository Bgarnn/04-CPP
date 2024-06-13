#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << CYAN << "Derived Cat: [" << this->type << "] created" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << CYAN << "Derived Cat: [" << this->type << "] copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Cat::Cat::~Cat(void)
{
	std::cout << CYAN << "Derived Cat: [" << this->type << "] destroyed" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << CYAN << "Derived Cat: [" << this->type << "] copy assignment called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}
