
#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
private:
	void	operator = (const TacticalMarine &s);
public:
	TacticalMarine();
	virtual ~TacticalMarine();
	TacticalMarine(const TacticalMarine &TacticalMarine);
	ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
