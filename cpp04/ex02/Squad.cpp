
#include "Squad.hpp"
#include <string>
#include <iostream>

Squad::Squad()
{
	_Amount = 0;
	_Marines = NULL;
}

void Squad::yeet(void)
{
	for (int i = 0; i < _Amount; i++)
		delete _Marines[i];
	delete [] _Marines;
}

Squad::~Squad()
{
	yeet();
}

Squad::Squad(const Squad &squad)
{
	_Amount = 0;
	*this = squad;
}

Squad& Squad::operator = (const Squad &s)
{
	if (&s != this)
	{
		if (_Amount > 0)
			yeet();
		
		_Amount = s._Amount;
		_Marines = new (std::nothrow) ISpaceMarine *[_Amount];
		if (!_Marines)
		{
			std::cout << "Allocation failed!" << std::endl;
			exit (1);
		}
		for (int i = 0; i < _Amount; i++)
			_Marines[i] = s._Marines[i]->clone();
	}
	return *this;
}

int Squad::getCount() const
{
	return _Amount;
}

ISpaceMarine* Squad::getUnit(int n) const
{
	if (n < _Amount)
		return _Marines[n];
	return NULL;
}

int Squad::push(ISpaceMarine* unit)
{
	if (!unit)
		return _Amount;
	for (int i = 0; i < _Amount; i++)
		if (_Marines[i] == unit)
			return _Amount;
	ISpaceMarine	**newMarines = new (std::nothrow) ISpaceMarine *[_Amount + 1];
	if (!newMarines)
	{
		std::cout << "Allocation failed!" << std::endl;
		return _Amount;
	}
	for (int i = 0; i < _Amount; i++)
		newMarines[i] = _Marines[i];
	delete[] _Marines;
	newMarines[_Amount] = unit;
	_Marines = newMarines;
	return ++_Amount;
}
