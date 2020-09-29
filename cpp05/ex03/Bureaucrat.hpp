
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		int					p_grade;
		const std::string	p_name;
		Bureaucrat();
	public:
		Bureaucrat(const std::string name, const int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator = (const Bureaucrat &s);
		std::string getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();
		void		signForm(AForm &tbs);
		void		executeForm(AForm const & form);

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

	
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& tbp);

#endif
