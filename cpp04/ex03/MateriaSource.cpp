
#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
	_Learned[0] = NULL;
	_Learned[1] = NULL;
}

MateriaSource::~MateriaSource()
{
}

void		MateriaSource::learnMateria(AMateria* toLearn)
{
	if (!toLearn)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_Learned[i] == toLearn)
			return ;
		if (!_Learned[i])
		{
			_Learned[i] = toLearn;
			std::cout << i << " | " << _Learned[i]->getType() << std::endl;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << _Learned[i]->getType() << " == " << type << std::endl;
		if (_Learned[i]->getType() == type)
		{
			std::cout << "boris helpt me en dat is wholesome!\n";
			return _Learned[i]->clone();
		}
	}
	return NULL;
}