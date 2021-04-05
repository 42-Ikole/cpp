
#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		virtual ~Cure();
		Cure(const Cure &Cure);
		Cure		&operator = (const Cure &s);
		AMateria*	clone() const;
		void		use(ICharacter& target);
	};

#endif
