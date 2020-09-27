
#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *learned[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &ms);
		void		operator = (const MateriaSource &s);
		void		learnMateria(AMateria* toLearn);
		AMateria*	createMateria(std::string const & type);
};

#endif
