
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	_Name = name;
	_ApCost = apcost;
	_Damage = damage;
}

AWeapon::~AWeapon() {}

AWeapon::AWeapon(const AWeapon &copy) : _Name(copy._Name), _Damage(copy._Damage), _ApCost(copy._ApCost){}

AWeapon	&AWeapon::operator = (const AWeapon &s )
{
	if (&s != this)
	{
		this->_Name = s._Name;
		this->_Damage = s._Damage;
		this->_ApCost = s._ApCost;
	}
	return *this;
}

std::string  AWeapon::getName() const
{
	return _Name;
}

void AWeapon::setName(std::string name)
{
	_Name = name;
}

int AWeapon::getApCost() const
{
	return _ApCost;
}

void AWeapon::setApCost(int cost)
{
	_ApCost = cost;
}

int AWeapon::getDamage() const
{
	return _Damage;
}

void AWeapon::setDamage(int damage)
{
	_Damage = damage;
}
