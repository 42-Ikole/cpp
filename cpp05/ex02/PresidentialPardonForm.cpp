
#include <PresidentialPardonForm.hpp>
#include <iostream>

//////////////////
// Constructors //
//////////////////

	PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("shrubbery", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC), _target(target)
	{
	}

	PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& x)
		: AForm("shrubbery copy", PresidentialPardonForm::SIGN, PresidentialPardonForm::EXEC)
	{
		*this = x;
	}

	PresidentialPardonForm::~PresidentialPardonForm()
	{}

	PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& x)
	{
		return *(this);
	}

/////////////
// Helpers //
/////////////

	void	PresidentialPardonForm::_action()
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n"
	}

///////////////
// Modifiers //
///////////////

	void PresidentialPardonForm::execute(const Bureaucrat& executor)
	{
		if (this->isSigned() == false)
			throw NotSigned();
		if (executor.getGrade() > this->getExecuteGradeRequired())
			throw GradeTooLowException();
		this->_action();
	}
