#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <AForm.hpp>
# include <string>

class PresidentialPardonForm : public AForm
{
	//////////
	// Enum //
	//////////
	public:

		enum e_grade {
			SIGN = 25,
			EXEC = 5
		} grade;

	//////////////////////
	// Member variables //
	//////////////////////
	private:

		const std::string	_target;

	//////////////////
	// Constructors //
	//////////////////
	private:

		PresidentialPardonForm();
	
	public:

		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& x);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator = (const PresidentialPardonForm& x);

	/////////////
	// Helpers //
	/////////////
	private:

		void	_action() const;

	///////////////
	// Modifiers //
	///////////////
	public:

		void execute(const Bureaucrat& executor) const;

}; /* end of PresidentialPardonForm */

#endif
