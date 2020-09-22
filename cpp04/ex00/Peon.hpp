
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
		Peon(const Peon &copy);
		void		getPolymorphed() const;
};

#endif