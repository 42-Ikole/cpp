#include <Intern.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <string>
#include <iostream>

//////////////////
// Constructors //
//////////////////

	Intern::Intern()
	{

	}

	Intern::Intern(const Intern& x)
	{
		*this = x;
	}

	Intern::~Intern()
	{
	}


	Intern& Intern::operator = (const Intern& x)
	{
		(void)x;
		return *(this);
	}

///////////////
// Modifiers //
///////////////

	const static char* forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	typedef AForm* (*f_form)(const std::string&);

	const static f_form create_form[] = {
		CreateShrubberyCreationForm,
		CreateRobotomyRequestForm,
		CreatePresidentialPardonForm
	};

	AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
	{
		for (size_t i = 0;  i < (sizeof(forms) / sizeof(char*)); ++i) {
			if (formName == forms[i]) {
				std::cout << "Intern creates " << formName << "\n";
				return create_form[i](target);
			}
		}
		throw FormNotFound();
	}
