
#ifndef Minigun_H
# define Minigun_H

# include "AMateria.hpp"
#include "ICharacter.hpp"

class Minigun : public AMateria
{
	private:

	public:
		Minigun();
		virtual ~Minigun();
		Minigun(const Minigun &Minigun);
		Minigun		&operator = (const Minigun &s);
		AMateria*	clone() const;
		void		use(ICharacter& target);
	};

#endif
