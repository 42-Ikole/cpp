
#ifndef PEON_H
# define PEON_H

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <string>

class Peon : public Victim
{
	private:
		Peon();
	public:
		Peon(std::string n);
		~Peon();
		void 		operator = (const Peon &s );
		Peon(const Peon &copy);
		void		getPolymorphed() const;
};

#endif