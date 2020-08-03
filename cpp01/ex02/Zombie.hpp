
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
public:
    std::string name;
    std::string type;
    void announce(Zombie zombie);
};

#endif