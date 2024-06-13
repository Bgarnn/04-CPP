#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << RED << "\n---------------------[Subject example]---------------------\n" << std::endl;
	const Animal* a = new Dog(); 
	const Animal* b = new Cat();
	delete a;
	delete b;

	std::cout << RED << "\n---------------------[Subject test]---------------------\n" << std::endl;
	Animal *meta[4];
	for (int i = 0; i < 2; i++)
		meta[i] = new Cat();
	for (int i = 2; i < 4; i++)
		meta[i] = new Dog();
	for (int i = 0; i < 4; i++)
	{
		std::cout << DEFAULT << meta[i]->getType() << ": ";
		meta[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
		delete meta[i];

	std::cout << RED << "\n---------------------[Brain DeepCopy Test]---------------------\n" << std::endl;
	std::cout << RED << "\n-->[Dog brain]\n" << std::endl;
	Dog i;
	{
		Dog tmp = i;
	}
	i.getBrain()->displayIdeas();

	std::cout << RED << "\n-->[Cat brain]\n" << std::endl;
	Cat j;
	{
		Cat tmp = j;
	}
	j.getBrain()->displayIdeas();
	return (0);
}