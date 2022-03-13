
#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <string>
#include <ostream>

/////////////
// Coplien //
/////////////

	Bureaucrat::Bureaucrat(const std::string name, short grade)
		: _name(name)
	{
		_gradeInRange(grade);
		this->_grade = grade;
	}

	Bureaucrat::Bureaucrat(const Bureaucrat& x)
	{
		*this = x;	
	}

	Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& x)
	{
		if (this == &x)
			return *(this);

		this->_grade = x._grade;
		return *(this);
	}

	Bureaucrat::~Bureaucrat()
	{}

/////////////
// Helpers //
/////////////

	void	Bureaucrat::_gradeInRange(short	grade)
	{
		if (grade <= 0)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}

/////////////
// Getters //
/////////////

	const std::string&	Bureaucrat::getName(void) const
	{
		return (_name);
	}

	short				Bureaucrat::getGrade(void) const
	{
		return (_grade);
	}

///////////////
// Modifiers //
//////////////

	void	Bureaucrat::incrementGrade(unsigned short n)
	{
		_gradeInRange(_grade - n);
		_grade -= n;
	}

	void	Bureaucrat::decrementGrade(unsigned short n)
	{
		_gradeInRange(_grade + n);
		_grade += n;
	}

	void	Bureaucrat::signForm(AForm& form)
	{
		try {
			form.beSigned(*this);
		}
		catch (std::exception& e) {
			std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
		}
	}

	void	Bureaucrat::executeForm(const AForm& form)
	{
		try {
			form.execute(*this);
			std::cout << this->getName() << " executed " << form.getName();
		} catch (const std::exception& e) {
			std::cerr << ERROR << e.what() << "\n";
		}
	}

////////////////////////
// Operator overloads //
////////////////////////

	std::ostream&	operator << (std::ostream& o, const Bureaucrat& x)
	{
		o << x.getName() << ", grade: " << x.getGrade();
		return (o);
	}
