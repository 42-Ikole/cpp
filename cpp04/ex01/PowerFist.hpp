
#ifndef POWERFIST_H
# define POWERFIST_H

#include "AWeapon.hpp"
#include <string>

class PowerFist : public AWeapon
{
	private:

	public:
		PowerFist();
		~PowerFist();
		PowerFist(const PowerFist &copy);
		PowerFist	&operator = (const PowerFist &s );
		void	attack() const;
};

#endif