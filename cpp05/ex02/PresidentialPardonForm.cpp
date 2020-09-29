
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("A presidential form", 25, 5)
{
	p_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
: AForm(copy)
{
	this->p_target = copy.p_target;
}

PresidentialPardonForm &	PresidentialPardonForm::operator = (const PresidentialPardonForm &s)
{
	if (&s != this)
	{
		this->p_target = s.p_target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->isSigned() == false)
		throw FNSE;
	if (executor.getGrade() > this->getGradeExec())
		throw GTLEE;
	std::cout << p_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
