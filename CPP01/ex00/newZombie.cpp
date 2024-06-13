#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*zombie_heap = new Zombie(name);
	return(zombie_heap);
}