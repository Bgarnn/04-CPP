#include "Zombie.hpp"

int main(void)
{
	int		n = 3;
	Zombie	*zombie_horde = zombieHorde(n, "gang");

	for (int i = 0; i < n; i++)
	{
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;
	return(0);
}