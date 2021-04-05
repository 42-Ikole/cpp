
#ifndef ASSAULTTERMINATOR_H
# define ASSAULTTERMINATOR_H

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
private:
	void	operator = (const AssaultTerminator &s);
public:
	AssaultTerminator();
	~AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &AssaultTerminator);
	AssaultTerminator *clone() const;
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;
};

#endif
