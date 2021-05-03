
#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <string>
#include <iostream>

Character::Character() {}

Character::Character(std::string const & name)
{
	_Name = name;
	_AP = 40;
	_Weapon = NULL;
}

Character::~Character() {}

Character::Character(const Character &copy) : _Name(copy._Name), _AP(copy._AP), _Weapon(copy._Weapon) {}

Character &Character::operator = (const Character &s )
{
	if (this != &s)
	{
		_Name = s._Name;
		_AP = s._AP;
		_Weapon = s._Weapon;
	}
	return *this;
}

void Character::recoverAP()
{
	if (_AP + 10 > 40)
		_AP = 40;
	else
		_AP += 10;

}

int	Character::getAP() const
{
	return _AP;
}

void Character::equip(AWeapon* weapon)
{
	_Weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
	if (!_Weapon || _AP < _Weapon->getApCost() || enemy->getHP() == 0 || _Weapon->getApCost() < 0)
		return ;
	_AP -= _Weapon->getApCost();
	std::cout << _Name << " attacks " << enemy->getType() << " with a " << _Weapon->getName() << std::endl;
	_Weapon->attack();
	enemy->takeDamage(_Weapon->getDamage());	
}

std::string Character::getName() const
{
	return _Name;
}

std::string		Character::getWeaponName() const
{
	if (!_Weapon)
		return "";
	return _Weapon->getName();
}

AWeapon	*Character::getWeapon() const
{
	return _Weapon;
}

std::ostream   &operator << (std::ostream &out, const Character &tbp)
{
	if (tbp.getWeapon() != NULL)
   		out << tbp.getName() << " has " << tbp.getAP() << " AP and wields a " << tbp.getWeaponName() << std::endl;
	else
		out << tbp.getName() << " has " << tbp.getAP() << " AP and is unarmed" << std::endl;
    return out;
}