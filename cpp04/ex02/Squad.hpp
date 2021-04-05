
#ifndef SQUAD_H
# define SQUAD_H

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	private:
		int				_Amount;
		ISpaceMarine	**_Marines;
	public:
		Squad();
		~Squad();
		Squad(const Squad &squad);
		Squad	&operator = (const Squad &s);
		int getCount() const;
		ISpaceMarine* getUnit(int n) const;
		int push(ISpaceMarine* unit);
};

#endif
