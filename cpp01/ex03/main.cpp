#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
	std::srand(time(NULL));
	std::cout << "testing 5 zombies!\n\n";
    ZombieHorde horde5 (5);

	std::cout << "\n\ntesting 42 zombies!\n\n";
    ZombieHorde horde42 (42);
	system("leaks a.out");
	return (0);
}