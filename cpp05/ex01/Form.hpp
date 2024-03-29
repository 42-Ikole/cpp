
#ifndef FORM_HPP
# define FORM_HPP

# include <Bureaucrat.hpp>
# include <ostream>
# include <string>
# include <exception>

class Form
{
	//////////////////////
	// Member variables //
	//////////////////////
	private:

		const std::string	_name;
		bool				_isSigned;
		const short			_signGrade;
		const short			_execGrade;
	
	//////////////////
	// Constructors //
	//////////////////
	private:

		Form();

	public:

		Form(const std::string name, short signGrade, short execGrade);
		Form(const Form& x);
		virtual ~Form();

		Form& operator = (const Form& x);

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
		short				getSignGradeRequired(void) const;
		short				getExecuteGradeRequired(void) const;
		bool				isSigned(void) const;

	///////////////
	// Modifiers //
	///////////////
	public:

		void	beSigned(const Bureaucrat& x);

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

		class AlreadySigned : public std::exception
		{
			const char* what() const throw() {
				return ("form is already signed");
			}
		};

}; /* end of form class */

////////////////////////
// Operator overloads //
////////////////////////

	std::ostream& operator << (std::ostream& o, const Form& x);

#endif
