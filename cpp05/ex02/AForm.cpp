
#include <AForm.hpp>
#include <string>
#include <iostream>
#include <ostream>

/////////////
// Coplien //
/////////////

	AForm::AForm(const std::string name, short signGrade, short execGrade)
		: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
	{
		_gradeInRange(signGrade);
		_gradeInRange(execGrade);
	}

	AForm::AForm(const AForm& x)
		: _name("copy"), _isSigned(false), _signGrade(69), _execGrade(42)
	{
		*this = x;	
	}

	AForm&	AForm::operator = (const AForm& x)
	{
		// nothing should be assigned...
		(void)x;
		return *(this);
	}

	AForm::~AForm()
	{}

/////////////
// Helpers //
/////////////

	void	AForm::_gradeInRange(short grade)
	{
		if (grade <= 0)
			throw AForm::GradeTooHighException();
		else if (grade > 150)
			throw AForm::GradeTooLowException();
	}

/////////////
// Getters //
/////////////

	const std::string&	AForm::getName(void) const
	{
		return (_name);
	}

	short				AForm::getSignGradeRequired(void) const
	{
		return (_signGrade);
	}
	
	short				AForm::getExecuteGradeRequired(void) const
	{
		return (_execGrade);
	}

	bool				AForm::isSigned(void) const
	{
		return (_isSigned);
	}

///////////////
// Modifiers //
//////////////

	void	AForm::beSigned(const Bureaucrat& x)
	{
		if (this->_isSigned == true)
			throw AlreadySigned();
		if (x.getGrade() > _signGrade)
			throw GradeTooLowException();
		_isSigned = true;
		std::cout << x.getName() << " signed " << this->_name << "\n";
	}

////////////////////////
// Operator overloads //
////////////////////////

	std::ostream&	operator << (std::ostream& o, const AForm& x)
	{
		o << x.getName() << ", grade required to sign: " << x.getSignGradeRequired();
		o << ", grade required to execute: " << x.getExecuteGradeRequired();
		o << std::boolalpha << " signed: " << x.isSigned();
		return (o);
	}
