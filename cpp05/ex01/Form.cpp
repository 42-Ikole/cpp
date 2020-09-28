
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form( const std::string name, const int grade) :
	p_name(name), 
	p_grade(grade), 
	p_isSigned(false)
{
	if (grade < 1)
		throw GTHE;
	else if (grade > 150)
		throw GTLE;
}

Form::~Form()
{}

Form::Form(const Form &copy) :
	p_name(copy.getName()),
	p_grade(copy.getGrade()),
	p_isSigned(copy.isSigned())
{}

Form & Form::operator = (const Form &s)
{
	if (&s != this)
	{
		this->p_isSigned = s.p_isSigned;
	}
	return *this;
}

void	Form::beSigned(const Bureaucrat &tbs)
{
	if (tbs.getGrade() < this->p_grade)
		this->p_isSigned = true;
	else
		throw GTLE;
}

bool			Form::isSigned() const
{
	return p_isSigned;
}

std::string		Form::getName() const
{
	return p_name;
}

int				Form::getGrade() const
{
	return p_grade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator << (std::ostream& os, const Form& tbp)
{
	os << "name = " << tbp.getName() <<
		", grade = " << tbp.getGrade() <<
		", signed = " << (tbp.isSigned() == true ? "true" : "false") << std::endl;
	return os;
}
