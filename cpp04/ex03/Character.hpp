
#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria	*inv[4];
		Character();
	public:
		Character(std::string _name);
		~Character();
		Character(const Character &character);
		void	operator = (const Character &character);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
