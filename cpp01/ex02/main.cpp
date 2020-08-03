#include <iostream>
#include <string>
#include <new>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent		zombie;

	zombie.randomChump();
	system("leaks a.out");
	return (0);
}