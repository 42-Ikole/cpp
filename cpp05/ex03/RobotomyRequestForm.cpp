
#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("robotomy request", 72, 45)
{
	p_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
: AForm(copy)
{
	this->p_target = copy.p_target;
}

RobotomyRequestForm &	RobotomyRequestForm::operator = (const RobotomyRequestForm &s)
{
	if (&s != this)
	{
		this->p_target = s.p_target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->isSigned() == false)
		throw FNSE;
	if (executor.getGrade() > this->getGradeExec())
		throw GTLEE;
	srand(time(NULL));
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << p_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << p_target << " is a failure!" << std::endl;
}
