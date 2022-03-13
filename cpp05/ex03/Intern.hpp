#ifndef INTERN_HPP
# define INTERN_HPP

# include <AForm.hpp>
# include <string>

class Intern
{
	//////////////////
	// Constructors //
	//////////////////
	public:

		Intern();
		Intern(const Intern& x);
		virtual ~Intern();

		Intern& operator = (const Intern& x);

	///////////////
	// Modifiers //
	///////////////
	public:

		AForm*	makeForm(const std::string& formName, const std::string& target);

	////////////////
	// exceptions //
	////////////////
	public:

		class FormNotFound : public std::exception
		{
			const char* what() const throw() {
				return ("Form not found");
			}
		};

}; /* end of intern class */

#endif
