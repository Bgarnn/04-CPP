#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << PINK <<"Derived WrongCat: [" << this->type << "] created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	if (this != &obj)
		*this = obj;
	std::cout << PINK << "Derived WrongCat: [" << this->type << "] copy constructor called" << std::endl;
}

WrongCat::WrongCat::~WrongCat(void)
{
	std::cout << PINK << "Derived WrongCat: [" << this->type << "] destroyed" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << PINK << "Derived WrongCat: [" << this->type << "] copy assignment called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}
