#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	player("Kawin");

	for (int i = 0; i < 11; i++)
	{
		player.attack("Monster");
	}
	for (int i = 0; i < 2; i++)
	{
		player.takeDamage(10);
	}
	player.beRepaired(1);
	player.takeDamage(1);
	return (0);
}
