#ifndef RADSCORPION_H
# define RADSCORPION_H

#include "Enemy.hpp"
#include <string>

class RadScorpion : public Enemy
{
	private:

	public:
		RadScorpion();
		virtual ~RadScorpion();
		RadScorpion(const RadScorpion &copy);
		RadScorpion	&operator = (const RadScorpion &s );
};

#endif