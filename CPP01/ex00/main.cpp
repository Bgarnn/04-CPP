#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie_m("zombie_m");
	zombie_m.announce();

	Zombie	*zombie_h = newZombie("zombie_h");
	zombie_h->announce();
	delete zombie_h;

	randomChump("zombie_s");

	return(0);
}