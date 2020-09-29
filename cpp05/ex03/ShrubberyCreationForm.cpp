
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("shrubbery creation", 145, 137)
{
	p_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
: AForm(copy)
{
	this->p_target = copy.p_target;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator = (const ShrubberyCreationForm &s)
{
	if (&s != this)
	{
		this->p_target = s.p_target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->isSigned() == false)
		throw FNSE;
	if (executor.getGrade() > this->getGradeExec())
		throw GTLEE;

	std::string file = p_target + "_shrubbery";
	std::ofstream ioFile(file);

	if (ioFile.is_open() == false)
		throw UTOF;
	for (int i = 0; i < 5; i++)
	{
		ioFile << "\
				 v\n\
		        >X<\n\
		         A\n\
		        d$b\n\
		      .d\\$$b.\n\
		    .d$i$$\\$$b.\n\
		       d$$@b\n\
		      d\\$$$ib\n\
		    .d$$$\\$$$b\n\
		  .d$$@$$$$\\$$ib.\n\
		      d$$i$$b\n\
		     d\\$$$$@$b\n\
		  .d$@$$\\$$$$$@b.\n\
		.d$$$$i$$$\\$$$$$$b.\n\
		        ###\n\
		        ###\n\
		        ###\n";
	}
	if (ioFile.fail() == true)
		throw EWW;
	ioFile.close();
}


const char *ShrubberyCreationForm::UnableToOpenFile::what() const throw()
{
	return "Unable to open target :(";
}

const char *ShrubberyCreationForm::ErrorWhileWriting::what() const throw()
{
	return "Error while writing!!!";
}
