
#include <iostream>
#include <string>
#include <new>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent	eskootit;
	Zombie		*zombie = eskootit.newZombie("zombol");
	Zombie		*zombert = eskootit.newZombie("fuckthisshitimout");

	zombie->announce();
	delete zombie;
	zombie = eskootit.randomChump();
	delete zombie;
	eskootit.setZombieType(zombert);
	zombert->announce();
	delete  zombert;

	return (0);
}