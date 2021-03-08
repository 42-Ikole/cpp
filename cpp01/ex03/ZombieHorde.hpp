#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include <new>
#include "Zombie.hpp"

std::string	generate_name();

class ZombieHorde
{
	Zombie  *horde;
    int     _amount;
public:
			~ZombieHorde();
            ZombieHorde(int number);
    void    announce(int nb, Zombie *horde);
};

#endif