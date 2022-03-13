
#include <PresidentialPardonForm.hpp>
#include <iostream>

//////////////////
// Constructors //
//////////////////

	PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("president", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC), _target(target)
	{
	}

	PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& x)
		: AForm("president copy", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC)
	{
		*this = x;
	}

	PresidentialPardonForm::~PresidentialPardonForm()
	{}

	PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& x)
	{
		(void)x;
		return *(this);
	}

/////////////
// Helpers //
/////////////

	void	PresidentialPardonForm::_action() const
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
	}

///////////////
// Modifiers //
///////////////

	void PresidentialPardonForm::execute(const Bureaucrat& executor) const
	{
		if (this->isSigned() == false)
			throw NotSigned();
		if (executor.getGrade() > this->getExecuteGradeRequired())
			throw GradeTooLowException();
		this->_action();
	}

AForm*	CreatePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
