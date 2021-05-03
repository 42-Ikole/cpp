
#ifndef MINIGUN_HPP
# define MINIGUN_HPP

#include "AWeapon.hpp"
#include <string>

class Minigun : public AWeapon
{
	private:

	public:
		Minigun();
		virtual ~Minigun();
		Minigun(const Minigun &copy);
		Minigun	&operator = (const Minigun &s );
		void	attack() const;
};

#endif