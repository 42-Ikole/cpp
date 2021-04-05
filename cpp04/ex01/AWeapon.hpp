
#ifndef AWEAPON_H
# define AWEAPON_H

#include <string>

class AWeapon
{
	protected:
		std::string _Name;
		int			_Damage;
		int			_ApCost;
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();
		AWeapon(const AWeapon &copy);
		AWeapon		&operator = (const AWeapon &s );
		std::string virtual getName() const;
		void virtual setName(std::string name);
		int		getApCost() const;
		void	setApCost(int cost);
		int		getDamage() const;
		void	setDamage(int damage);
		virtual void attack() const = 0;
};

#endif
