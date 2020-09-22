
#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include <string>

class Victim;
class Peon;

class Sorcerer
{
	private:
		Sorcerer();
		std::string _name;
		std::string _title;
	public:
		Sorcerer(std::string n, std::string t);
		~Sorcerer();
		Sorcerer(const Sorcerer &copy);
		std::string	getName() const;
		std::string	getTitle() const;
		void 		polymorph(Victim const &target) const;
};

std::ostream	&operator << (std::ostream &out, const Sorcerer &tbp);

#endif
