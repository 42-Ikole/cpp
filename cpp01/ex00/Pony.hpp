
#ifndef PONY_H
# define PONY_H

#include <string>

class Pony
{
	std::string	_name;
	int			_speed;
	int			_stamina;
	int			_cooldown;
				Pony(void);
public:
				Pony(std::string name, int speed, int stamina, int cooldown);
	std::string getName(void);
	int			calcTime(void);
};

	void		ponyOnTheHeap(void);
	void		ponyOnTheStack(void);

#endif
