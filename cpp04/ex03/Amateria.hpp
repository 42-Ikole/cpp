
#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
class ICharacter;

class AMateria
{
	private:
		unsigned int	xp;
		std::string		type;
		AMateria();
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria &amateria);
		void	operator = (const AMateria &amateria);
		std::string const & getType() const; //Returns the materia type
		void				setType(std::string type);
		unsigned int 		getXP() const; //Returns the Materia's XP
		void				setXP(int xp);
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
