
#include <Form.hpp>
#include <string>
#include <iostream>
#include <ostream>

/////////////
// Coplien //
/////////////

	Form::Form(const std::string name, short gradeRequired)
		: _name(name), _isSigned(false)
	{
		_gradeInRange(gradeRequired);
		this->_gradeRequired = gradeRequired;
	}

	Form::Form(const Form& x)
	{
		*this = x;	
	}

	Form&	Form::operator = (const Form& x)
	{
		if (this == &x)
			return *(this);

		this->_gradeRequired = x._gradeRequired;
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

	short				Form::getGradeRequired(void) const
	{
		return (_gradeRequired);
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
		if (x.getGrade() > _gradeRequired)
			throw GradeTooLowException();
		_isSigned = true;
		std::cout << x.getName() << " signed " << this->_name << "\n";
	}

////////////////////////
// Operator overloads //
////////////////////////

	std::ostream&	operator << (std::ostream& o, Form& x)
	{
		o << x.getName() << ", grade required: " << x.getGradeRequired() << std::boolalpha << "signed: " << x.isSigned();
		return (o);
	}
