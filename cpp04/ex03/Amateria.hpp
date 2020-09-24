
#ifndef AMATERIA_H
# define AMATERIA_H

class AMateria
{
	private:
	[...]
	unsigned int _xp;
	public:
	AMateria(std::string const & type);
	[...]
	[...] ~AMateria();
	std::string const & getType() const; //Returns the materia type
	unsigned int getXP() const; //Returns the Materia's XP
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif
