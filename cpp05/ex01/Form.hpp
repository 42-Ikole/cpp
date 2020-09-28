
#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	p_name;
		const int			p_grade;
		bool				p_isSigned;
		Form();
	public:
		Form(const std::string name, const int grade);
		~Form();
		Form(const Form &copy);
		Form & operator = (const Form &s);
		bool			isSigned() const;
		std::string		getName() const;
		int				getGrade() const;
		void			beSigned(const Bureaucrat &tbs);

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

std::ostream& operator << (std::ostream& os, const Form& tbp);

#endif
