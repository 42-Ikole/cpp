
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm( const std::string name, const int gradeSign, const int gradeExec) :
	p_name(name), 
	p_gradeSign(gradeSign),
	p_gradeExec(gradeExec),
	p_isSigned(false)
{
	if (gradeSign < 1 || gradeExit < 1)
		throw GTHE;
	else if (gradeExec > 150 || gradeSign > 150)
		throw GTLE;
}

AForm::~AForm()
{}

AForm::AForm(const AForm &copy) :
	p_name(copy.getName()),
	p_gradeSign(copy.getGradeSign()),
	p_gradeExec(copy.getGradeExec()),
	p_isSigned(copy.isSigned())
{}

AForm & AForm::operator = (const AForm &s)
{
	if (&s != this)
	{
		this->p_isSigned = s.p_isSigned;
	}
	return *this;
}

void	AForm::beSigned(const Bureaucrat &tbs)
{
	if (tbs.getGrade() < this->p_gradeSign)
		this->p_isSigned = true;
	else
		throw GTLES;
}

bool			AForm::isSigned() const
{
	return p_isSigned;
}

std::string		AForm::getName() const
{
	return p_name;
}

int				AForm::getGradeSign() const
{
	return p_gradeSign;
}

int				AForm::getGradeExec() const
{
	return p_gradeExec;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator << (std::ostream& os, const AForm& tbp)
{
	os << "name = " << tbp.getName() <<
		", sign grade = " << tbp.getGradeSign() <<
		", exec grade = " << tbp.getGradeExec() <<
		", signed = " << (tbp.isSigned() == true ? "true" : "false") << std::endl;
	return os;
}


const char* AForm::FormNotSignedException::what() const throw()
{
	return "unable to execute becasue the form is not signed";
}

const char* AForm::GradeTooLowExceptionSign::what() const throw()
{
	return "Unable to sign form because: Grade is too low";
}

const char* AForm::GradeTooLowExceptionExec::what() const throw()
{
	return "Unable to execute form because: grade is too low";
}