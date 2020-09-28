
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, const int grade) : p_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->p_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : p_name(copy.p_name)
{
	this->p_grade = copy.p_grade;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &s)
{
	if (&s != this)
	{
		this->p_grade = s.p_grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->p_name;
}

int			Bureaucrat::getGrade() const
{
	return this->p_grade;
}

void		Bureaucrat::incGrade()
{
	if (p_grade > 1)
		p_grade--;
	else
		throw GradeTooHighException();
}

void		Bureaucrat::decGrade()
{
	if (p_grade < 150)
		p_grade++;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& tbp)
{
	os << tbp.getName() << ", bureaucrat grade: " << tbp.getGrade() <<  std::endl;
	return os;
}
