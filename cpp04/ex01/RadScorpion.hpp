#ifndef RADSCORPION_H
# define RADSCORPION_H

#include "Enemy.hpp"
#include <string>

class RadScorpion : public Enemy
{
	private:

	public:
		RadScorpion();
		~RadScorpion();
		RadScorpion(const RadScorpion &copy);
		void 		operator = (const RadScorpion &s );
};

#endif