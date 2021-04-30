
#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
class ICharacter;

class AMateria
{
	protected:
		unsigned int	xp;
		std::string		type;
		AMateria();
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria &amateria);
		AMateria	&operator = (const AMateria &amateria);
		std::string const & getType() const;
		void				setType(std::string type);
		unsigned int 		getXP() const; 
		void				setXP(int xp);
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
