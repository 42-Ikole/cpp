
#ifndef CORONA_H
# define CORONA_H

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <string>

class Corona : public Victim
{
	private:
		Corona();
	public:
		Corona(std::string n);
		virtual ~Corona();
		Corona	&operator = (const Corona &s );
		Corona(const Corona &copy);
		void		getPolymorphed() const;
};

#endif