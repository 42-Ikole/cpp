#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
    public:
        void    setZombieType(Zombie *zombie);
        Zombie* newZombie(std::string name);
        void    randomChump();
};

std::string     generate_name();

#endif
