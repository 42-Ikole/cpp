
#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		int	arrLength(AForm **choices);
	public:
		Intern();
		~Intern();

		AForm*	makeForm(std::string form, std::string target);
};

#endif
