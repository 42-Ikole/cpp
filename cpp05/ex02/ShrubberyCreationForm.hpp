
#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string p_target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &	operator = (const ShrubberyCreationForm &s);
		void	execute(Bureaucrat const & executor) const;
	
	class UnableToOpenFile : public std::exception
	{
		public:
			const char* what() const throw();
	} UTOF;

	class ErrorWhileWriting : public std::exception
	{
		public:
			const char* what() const throw();
	} EWW;
};

#endif
