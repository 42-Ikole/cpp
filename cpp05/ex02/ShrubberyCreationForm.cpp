
#include <ShrubberyCreationForm.hpp>
#include <fstream>

//////////////////
// Constructors //
//////////////////

	ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("shrubbery", ShrubberyCreationForm::SIGN, ShrubberyCreationForm::EXEC), _target(target)
	{
	}

	ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& x)
		: AForm("shrubbery copy", ShrubberyCreationForm::SIGN, ShrubberyCreationForm::EXEC)
	{
		*this = x;
	}

	ShrubberyCreationForm::~ShrubberyCreationForm()
	{}

	ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& x)
	{
		(void)x;
		return *(this);
	}

/////////////
// Helpers //
/////////////

	void	ShrubberyCreationForm::_action() const
	{
		std::ofstream ioFile(_target + "_shrubbery");

		if (ioFile.is_open() == false)
			throw FailedToOpenFile();

		ioFile << "ASCII trees\n";

		if (ioFile.fail() == true)
			throw FailedToWriteFile();

		ioFile.close();
	}

///////////////
// Modifiers //
///////////////

	void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
	{
		if (this->isSigned() == false)
			throw NotSigned();
		if (executor.getGrade() > this->getExecuteGradeRequired())
			throw GradeTooLowException();
		this->_action();
	}
