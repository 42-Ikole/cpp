
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
	private:
		int					p_grade;
		const std::string	p_name;
		Bureaucrat();
	public:
		Bureaucrat(const std::string name, const int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator = (const Bureaucrat &s);
		std::string getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& tbp);

#endif
