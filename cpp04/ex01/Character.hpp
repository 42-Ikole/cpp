
#ifndef CHARACTER_H
# define CHARACTER_H

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <string>

class Character
{
	private:
		std::string _Name;
		int			_AP;
		AWeapon		*_Weapon;
		Character();
	public:
		Character(std::string const & name);
		~Character();
		Character(const Character &copy);
		void	operator = (const Character &s );
		void	recoverAP();
		void	equip(AWeapon* weapon);
		void	attack(Enemy* enemy);
		std::string virtual getName() const;
		int		getAP() const;
		std::string getWeaponName() const;
		AWeapon		*getWeapon() const;
};

std::ostream   &operator << (std::ostream &out, const Character &tbp);

#endif