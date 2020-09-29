
#ifndef INTERN_HPP
# define INTERN_HPP

#include <exception>
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
	
	class UnknownClassIdentifier : public std::exception
	{
		const char* what() const throw();
	} UCI;
};

#endif
