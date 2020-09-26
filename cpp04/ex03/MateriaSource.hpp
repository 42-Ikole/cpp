
#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_Learned[2];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria* toLearn);
		AMateria* createMateria(std::string const & type);
};

#endif
