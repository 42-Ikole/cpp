#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>
# include <string>

class RobotomyRequestForm : public AForm
{
	//////////
	// Enum //
	//////////
	public:

		enum e_grade {
			SIGN = 72,
			EXEC = 45
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

		RobotomyRequestForm();
	
	public:

		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& x);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator = (const RobotomyRequestForm& x);

	/////////////
	// Helpers //
	/////////////
	private:

		void	_action() const;

	///////////////
	// Modifiers //
	///////////////
	public:

		virtual void execute(const Bureaucrat& executor) const;

}; /* end of RobotomyRequestForm */

#endif
