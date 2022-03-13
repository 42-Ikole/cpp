
#ifndef AFORM_HPP
# define AFORM_HPP

# include <Bureaucrat.hpp>
# include <ostream>
# include <string>
# include <exception>

class AForm
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

		AForm();

	public:

		AForm(const std::string name, short signGrade, short execGrade);
		AForm(const AForm& x);
		virtual ~AForm();

		AForm& operator = (const AForm& x);

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

		void			beSigned(const Bureaucrat& x);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
				return ("Aform is already signed");
			}
		};

}; /* end of Aform class */

////////////////////////
// Operator overloads //
////////////////////////

	std::ostream& operator << (std::ostream& o, const AForm& x);

#endif
