#ifndef PONY_H
# define PONY_H

#include <string>

class Pony
{
    private:
	std::string	name;
	int			speed;
	int			stamina;
	int			cooldown;
	public:
	void    ponyOnTheHeap(void);
	void    ponyOnTheStack(void);
};



#endif
