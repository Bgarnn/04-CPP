#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->_brain = new Brain();
	this->_brain->setIdeas("Meow");
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
	delete this->_brain;
	std::cout << CYAN << "Derived Cat: [" << this->type << "] destroyed" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << CYAN << "Derived Cat: [" << this->type << "] copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		this->_brain = new Brain(*obj.getBrain());
	}
	return (*this);
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}
