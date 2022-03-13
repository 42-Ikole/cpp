
#include <RobotomyRequestForm.hpp>
#include <random>
#include <iostream>

//////////////////
// Constructors //
//////////////////

	RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("shrubbery", RobotomyRequestForm::SIGN, RobotomyRequestForm::EXEC), _target(target)
	{
	}

	RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& x)
		: AForm("shrubbery copy", RobotomyRequestForm::SIGN, RobotomyRequestForm::EXEC)
	{
		*this = x;
	}

	RobotomyRequestForm::~RobotomyRequestForm()
	{}

	RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& x)
	{
		(void)x;
		return *(this);
	}

/////////////
// Helpers //
/////////////

	void	RobotomyRequestForm::_action() const
	{
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully!\n";
		else
			std::cout << "robotomy failed!\n";
	}

///////////////
// Modifiers //
///////////////

	void RobotomyRequestForm::execute(const Bureaucrat& executor) const
	{
		if (this->isSigned() == false)
			throw NotSigned();
		if (executor.getGrade() > this->getExecuteGradeRequired())
			throw GradeTooLowException();
		this->_action();
	}
