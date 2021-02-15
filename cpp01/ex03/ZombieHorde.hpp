#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include <new>
#include "Zombie.hpp"

std::string	generate_name();

class ZombieHorde
{
    int     _amount;
public:
            ZombieHorde(int number);
    void    announce(int nb, Zombie *horde);
};

#endif