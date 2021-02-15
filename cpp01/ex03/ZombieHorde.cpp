#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int number) : 
_amount(number)
{
	Zombie *horde;

	try {
		horde = new Zombie[_amount];
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		exit (0);
	}
	for (int i = 0; i < _amount; i++) {
		horde[i].setname(generate_name());
		horde[i].settype("Horde");
	}
	announce(_amount, horde);
	delete[] horde;
}

void    ZombieHorde::announce(int nb, Zombie *horde)
{
    for (int i = 0; i < nb; i++) {
        horde[i].announce(horde[i]);
    }
}

std::string	generate_name()
{
	std::string name;
	char 		consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
	char 		vowels[] = {'a','e','i','o','u','y'};

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
