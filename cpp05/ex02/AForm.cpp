
#include <Form.hpp>
#include <string>
#include <iostream>
#include <ostream>

/////////////
// Coplien //
/////////////

	Form::Form(const std::string name, short signGrade, short execGrade)
		: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
	{
		_gradeInRange(signGrade);
		_gradeInRange(execGrade);
	}

	Form::Form(const Form& x)
		: _name("copy"), _isSigned(false), _signGrade(69), _execGrade(42)
	{
		*this = x;	
	}

	Form&	Form::operator = (const Form& x)
	{
		// nothing should be assigned...
		(void)x;
		return *(this);
	}

	Form::~Form()
	{}

/////////////
// Helpers //
/////////////

	void	Form::_gradeInRange(short grade)
	{
		if (grade <= 0)
			throw Form::GradeTooHighException();
		else if (grade > 150)
			throw Form::GradeTooLowException();
	}

/////////////
// Getters //
/////////////

	const std::string&	Form::getName(void) const
	{
		return (_name);
	}

	short				Form::getSignGradeRequired(void) const
	{
		return (_signGrade);
	}
	
	short				Form::getExecuteGradeRequired(void) const
	{
		return (_execGrade);
	}

	bool				Form::isSigned(void) const
	{
		return (_isSigned);
	}

///////////////
// Modifiers //
//////////////

	void	Form::beSigned(const Bureaucrat& x)
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

	std::ostream&	operator << (std::ostream& o, const Form& x)
	{
		o << x.getName() << ", grade required to sign: " << x.getSignGradeRequired();
		o << ", grade required to execute: " << x.getExecuteGradeRequired();
		o << std::boolalpha << " signed: " << x.isSigned();
		return (o);
	}
