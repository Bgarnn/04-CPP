#include "Brain.hpp"

Brain::Brain(void)
{
	this->setIdeas("...");
	std::cout << PINK << "Brain created" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << PINK << "Brain copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Brain::~Brain(void)
{
	std::cout << PINK << "Brain has destroyed" << std::endl;
}

Brain	&Brain::operator=(const Brain &obj)
{
	std::cout << PINK << "Brain copy assignment called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

void	Brain::displayIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << DEFAULT << this->ideas[i] << " ";
	std::cout << std::endl;

}

void	Brain::setIdeas(const std::string ideas)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas;
}
