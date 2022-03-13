#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <AForm.hpp>
# include <string>

class ShrubberyCreationForm : public AForm
{
	//////////
	// Enum //
	//////////
	public:

		enum e_grade {
			SIGN = 145,
			EXEC = 137
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

		ShrubberyCreationForm();
	
	public:

		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& x);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& x);

	/////////////
	// Helpers //
	/////////////
	private:

		void	_action() const;

	///////////////
	// Modifiers //
	///////////////
	public:

		void execute(const Bureaucrat& executor) const ;

	////////////////
	// Exceptions //
	////////////////
	public:

		class FailedToOpenFile : public std::exception
		{
			const char* what() const throw() {
				return ("failed to open file");
			}
		};
		
		class FailedToWriteFile : public std::exception
		{
			const char* what() const throw() {
				return ("failed to write to file");
			}
		};

}; /* end of ShrubberyCreationForm */

AForm*	CreateShrubberyCreationForm(const std::string& target);

#endif
