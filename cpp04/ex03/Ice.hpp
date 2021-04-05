
#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice &Ice);
		Ice	&operator = (const Ice &s);
		AMateria*	clone() const;
		void		use(ICharacter& target);
	};

#endif
