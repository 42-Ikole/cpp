
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
	for (int i = 0; i < 4; i++)
		this->learned[i] = ms.learned[i];
}

MateriaSource	&MateriaSource::operator = (const MateriaSource &s)
{
	if (&s != this)
	{
		for (int i = 0; i < 4; i++)
			this->learned[i] = s.learned[i];
	}
	return *this;
}

void		MateriaSource::learnMateria(AMateria* toLearn)
{
	if (!toLearn)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->learned[i])
		{
			this->learned[i] = toLearn;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->learned[i]->getType() == type)
		{
			return this->learned[i]->clone();
		}
	}
	return NULL;
}