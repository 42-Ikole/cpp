
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	private:
    	std::string name;
    	std::string type;
	public:
    	void 		announce();
		void 		settype(std::string);
		void 		setname(std::string);
		std::string	gettype(void);
		std::string	getname(void);
};

#endif