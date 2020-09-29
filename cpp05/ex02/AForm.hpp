
#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	p_name;
		const int			p_gradeSign;
		const int			p_gradeExec;
		bool				p_isSigned;
		AForm();
	public:
		AForm(const std::string name, const int gradeSign, const int gradeExec);
		~AForm();
		AForm(const AForm &copy);
		AForm & operator = (const AForm &s);
		bool			isSigned() const;
		std::string		getName() const;
		int				getGradeSign() const;
		int				getGradeExec() const;
		void			beSigned(const Bureaucrat &tbs);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	} GTHE;

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	} GTLE;

	class	FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	} FNSE;

	class GradeTooLowExceptionSign : public std::exception
	{
		public:
			const char* what() const throw();
	} GTLES;

	class GradeTooLowExceptionExec : public std::exception
	{
		public:
			const char* what() const throw();
	} GTLEE;
};

std::ostream& operator << (std::ostream& os, const AForm& tbp);

#endif
