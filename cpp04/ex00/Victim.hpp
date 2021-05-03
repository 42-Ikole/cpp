
#ifndef VICTIM_H
# define VICTIM_H

#include "Sorcerer.hpp"
#include <string>

class Victim
{
	private:
		Victim();
	protected:
		std::string _name;
	public:
		Victim(std::string n);
		virtual ~Victim();
		Victim(const Victim &copy);
		Victim 			&operator = (const Victim &s );
		std::string		getName() const;
		virtual void	getPolymorphed() const;
};

std::ostream	&operator << (std::ostream &out, const Victim &tbp);

#endif