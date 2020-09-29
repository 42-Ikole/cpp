
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern()
{
}

Intern::~Intern()
{
}

int	Intern::arrLength(AForm **choices)
{
	int i = 0;

	while (choices[i])
		i++;
	return i;
}

AForm*		Intern::makeForm(std::string form, std::string target)
{
	AForm *ret = NULL;
	AForm *choices[] = {
			new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target), 
			new PresidentialPardonForm(target),
			NULL
			};

	for (int i = 0; i < this->arrLength(choices); i++)
	{
		if (form.compare(choices[i]->getName()) != 0)
			delete choices[i];
		else
			ret = choices[i];
	}
	if (ret == NULL)
		throw UCI;
	return ret;
}

const char* Intern::UnknownClassIdentifier::what() const throw()
{
	return "unknown class identifier";
}