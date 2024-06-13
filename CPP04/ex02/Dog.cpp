#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->_brain = new Brain();
	this->_brain->setIdeas("Woof");
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
	delete this->_brain;	
	std::cout << GREEN << "Derived Dog: [" << this->type << "] destroyed" << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << GREEN << "Derived Dog: [" << this->type << "] copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		this->_brain = new Brain(*obj.getBrain());
	}
	return (*this);
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}
