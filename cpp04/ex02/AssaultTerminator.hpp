
#ifndef ASSAULTTERMINATOR_H
# define ASSAULTTERMINATOR_H

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
private:
	
public:
	AssaultTerminator();
	~AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &AssaultTerminator);
	void	operator = (const AssaultTerminator &s);
	AssaultTerminator *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
