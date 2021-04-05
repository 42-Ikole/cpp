
#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

#include "Enemy.hpp"
#include <string>

class SuperMutant : public Enemy
{
	private:

	public:
		SuperMutant();
		~SuperMutant();
		SuperMutant(const SuperMutant &copy);
		SuperMutant	&operator = (const SuperMutant &s );
		void	takeDamage(int damage);
};

#endif
