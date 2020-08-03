#ifndef PONY_H
# define PONY_H

#include <string>

class Pony
{
    public:
	std::string	name;
	int			speed;
	int			stamina;
	int			cooldown;
};


void    ponyOnTheHeap(void);
void    ponyOnTheStack(void);

#endif
