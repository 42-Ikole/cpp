
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string p_target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &	operator = (const PresidentialPardonForm &s);
		void	execute(Bureaucrat const & executor) const;
};

#endif
