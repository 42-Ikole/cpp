
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <exception>

Bureaucrat::Bureaucrat(const std::string name, const int grade) : p_name(name)
{
	if (grade < 1)
		throw GTHE;
	else if (grade > 150)
		throw GTLE;
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
		throw GTHE;
}

void		Bureaucrat::decGrade()
{
	if (p_grade < 150)
		p_grade++;
	else
		throw GTLE;
}

void	Bureaucrat::signForm(AForm &tbs)
{
	try {
		tbs.beSigned(*this);
		std::cout << this->getName() << " Signed form: " << tbs.getName() << std::endl;
	}
	catch (std::exception & msg) {
		std::cout << tbs.getName() <<  ", " << msg.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed "<< form.getName() << " successfully!" << std::endl;
	}
	catch (const std::exception &msg) {
		std::cout << msg.what() << std::endl;
	}
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
