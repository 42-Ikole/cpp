#include <iostream>
#include <string>
#include <new>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void    ZombieEvent::setZombieType(Zombie *zombie)
{
    zombie->settype("BRAINDEAD");
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie *new_zombie;

    try
    {
        new_zombie = new Zombie;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    new_zombie->setname(name);
	setZombieType(new_zombie);
	return (new_zombie);
}

std::string	generate_name()
{
	std::string name;
	char 		consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
	char 		vowels[] = {'a','e','i','o','u','y'};

	std::srand(time(NULL));
	int random = rand() % 2;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (random < 2 && count < 2) {
			name.push_back(consonents[rand() % 20]);
			count++;
		} else {
			name.push_back(vowels[rand() % 6]);
		}
		random = rand() % 2;
	}
	return (name);
}

void    ZombieEvent::randomChump()
{
    Zombie *zombie;
	
    zombie = newZombie(generate_name());
	zombie->announce();
	delete zombie;
}
