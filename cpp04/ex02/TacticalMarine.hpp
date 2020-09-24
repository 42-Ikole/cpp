
#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
private:
	
public:
	TacticalMarine();
	~TacticalMarine();
	TacticalMarine(const TacticalMarine &TacticalMarine);
	void	operator = (const TacticalMarine &s);
	ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
