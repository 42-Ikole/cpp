
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, const int _grade)
{
	this->name = _name;
	if (!(grade >= 1 && grade <= 150))
		throw "Grade is out of bounds;";
	else
		this->grade = _grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->name = copy.name;
	this->grade = copy.grade;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &s)
{
	if (&s != this)
	{
		this->grade = s.grade;
		this->name = s.name;
	}
	return *this;
}

std::string Bureaucrat::getName()
{
	return this->name;
}

int			Bureaucrat::getGrade()
{
	return this->grade;
}

void		Bureaucrat::incGrade()
{
	if (grade > 1)
		grade--;
}

void		Bureaucrat::decGrade()
{
	if (grade < 150)
		grade++;
}