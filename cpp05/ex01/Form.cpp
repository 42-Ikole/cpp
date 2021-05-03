
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form( const std::string name, const int gradeSign, const int gradeExec) :
	p_name(name), 
	p_gradeSign(gradeSign),
	p_gradeExec(gradeExec),
	p_isSigned(false)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GTHE;
	else if (gradeExec > 150 || gradeSign > 150)
		throw GTLE;
}

Form::~Form()
{}

Form::Form(const Form &copy) :
	p_name(copy.getName()),
	p_gradeSign(copy.getGradeSign()),
	p_gradeExec(copy.getGradeExec()),
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
	if (tbs.getGrade() < this->p_gradeSign)
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

int				Form::getGradeSign() const
{
	return p_gradeSign;
}

int				Form::getGradeExec() const
{
	return p_gradeExec;
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
		", sign grade = " << tbp.getGradeSign() <<
		", exec grade = " << tbp.getGradeExec() <<
		", signed = " << (tbp.isSigned() == true ? "true" : "false") << std::endl;
	return os;
}
