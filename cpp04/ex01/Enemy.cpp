
#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
{
	_HP = hp;
	_Type = type;
}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy &copy) : _Type(copy._Type), _HP(copy._HP) {}

void 		Enemy::operator = (const Enemy &s )
{
	if (&s != this)
	{
		_Type = s._Type;
		_HP = s._HP;
	}
}

std::string Enemy::getType() const
{
	return _Type;
}

void Enemy::setType(std::string type)
{
	_Type = type;
}

int Enemy::getHP() const
{
	return _HP;
}

void Enemy::setHP(int hp)
{
	_HP = hp;
}

void Enemy::takeDamage(int damage)
{
	if (_HP - damage <= 0)
		_HP = 0;
	else
		_HP -= damage;
	if (_HP == 0)
		delete this;
}
