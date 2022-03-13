
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

//////////////////////////
// forward declerations //
//////////////////////////

	class AForm;

///////////////////
// COLOR DEFINES //
///////////////////

	# define COLOR_RED		"\033[31m"
	# define COLOR_GREEN	"\033[32m"
	# define COLOR_YELLOW	"\033[33m"

	# define COLOR_LBLUE 	"\033[38;5;51m"
	# define COLOR_ORANGE	"\033[38;5;214m"
	# define COLOR_PINK		"\033[38;5;205m"

	# define COLOR_RESET	"\033[0m"

//////////////
// Messages //
//////////////

	# define ERROR		COLOR_RED "ERROR: " COLOR_RESET
	# define CREATED	COLOR_GREEN "Created: " COLOR_RESET
	# define INCR		COLOR_YELLOW "Incremented: " COLOR_RESET
	# define DECR		COLOR_ORANGE "Decremented: " COLOR_RESET
	# define ASSIGN		COLOR_LBLUE	"Assigned: " COLOR_RESET

class Bureaucrat
{
	private:

		const std::string	_name;
		short 				_grade;

	//////////////////
	// Constructors //
	//////////////////
	private:

		Bureaucrat();

	public:

		Bureaucrat(const std::string name, short grade);
		Bureaucrat(const Bureaucrat& x);
		virtual ~Bureaucrat();

		Bureaucrat& operator = (const Bureaucrat& x);
	
	/////////////
	// Helpers //
	/////////////
	private:

		void	_gradeInRange(short	grade);

	/////////////
	// Getters //
	/////////////
	public:

		const std::string&	getName(void) const;
		short				getGrade(void) const;

	///////////////
	// Modifiers //
	///////////////
	public:

		void	incrementGrade(unsigned short n = 1);
		void	decrementGrade(unsigned short n = 1);
		void	signForm(AForm& form);
		void	executeForm(const AForm& form);

	////////////////
	// Exceptions //
	////////////////
	public:

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw() {
				return ("grade too high");
			}
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw() {
				return ("grade too low");
			}
		};

}; /* Bureaucrat */

////////////////////////
// Operator overloads //
////////////////////////

	std::ostream& operator << (std::ostream& o, const Bureaucrat& x);

#endif
