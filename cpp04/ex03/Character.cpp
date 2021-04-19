
#include "Character.hpp"
#include <string>

Character::Character(std::string _name) : name(_name)
{
	for (int i = 0; i < 4; i++)
		this->inv[0] = NULL;
}

Character::~Character()
{
}

Character::Character(const Character &character)
{
	this->name = character.name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = character.inv[i];
}

Character	&Character::operator = (const Character &character)
{
	this->name = character.name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = character.inv[i];
	return *this;
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; m && i < 4; i++)
	{
		if (!this->inv[i])
		{
			this->inv[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inv[idx])
		this->inv[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inv[idx])
		this->inv[idx]->use(target);
}
