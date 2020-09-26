
#include "Character.hpp"
#include <string>

Character::Character(std::string name) : _Name(name)
{
	for (int i = 0; i < 4; i++)
		_Inv[0] = NULL;
}

Character::~Character()
{
}

std::string const & Character::getName() const
{
	return _Name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; m && i < 4; i++)
	{
		if (_Inv[i] == m)
			return ;
		if (!_Inv[i])
			_Inv[i] = m;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _Inv[idx])
		_Inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _Inv[idx])
		_Inv[idx]->use(target);
}
