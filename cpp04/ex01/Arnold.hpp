
#ifndef ARNOLD_HPP
# define ARNOLD_HPP

#include "Enemy.hpp"
#include <string>

class Arnold : public Enemy
{
	private:

	public:
		Arnold();
		virtual ~Arnold();
		Arnold(const Arnold &copy);
		Arnold	&operator = (const Arnold &s );
		void	takeDamage(int damage);
};

#endif
