
#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

#include "AWeapon.hpp"
#include <string>

class PlasmaRifle : public AWeapon
{
	private:

	public:
		PlasmaRifle();
		~PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &copy);
		PlasmaRifle	&operator = (const PlasmaRifle &s );
		void	attack() const;
};

#endif