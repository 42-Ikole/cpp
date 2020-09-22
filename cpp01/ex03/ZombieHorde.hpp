#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include <new>
#include "Zombie.hpp"

std::string	generate_name();

class ZombieHorde
{
private:
    int amount;
public:
    ZombieHorde(int number): amount(number)
    {
        Zombie *horde;

        try {
            horde = new Zombie[amount];
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            exit (0);
        }
        for (int i = 0; i < amount; i++) {
            horde[i].setname(generate_name());
            horde[i].settype("Horde");
        }
        announce(amount, horde);
        delete[] horde;
    }

    void    announce(int nb, Zombie *horde);
};

#endif