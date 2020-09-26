
#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
class ICharacter;

class AMateria
{
	private:
		unsigned int	_xp;
		std::string		_Type;
		AMateria();
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		void				setType(std::string type);
		unsigned int 		getXP() const; //Returns the Materia's XP
		void				setXP(int xp);
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
