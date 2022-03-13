
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <string>
#include <iostream>

static void	bureaucrat_constructors(void)
{
	// should work fine
	try {
		Bureaucrat snorlax("Snorlax", 69);
		std::cout << CREATED << snorlax << "\n";

		Bureaucrat nb1("De nummer 1", 1);
		std::cout << CREATED << nb1 << "\n";

		Bureaucrat pleb("Pleb", 150);
		std::cout << CREATED << pleb << "\n";

		Bureaucrat dub(pleb);
		std::cout << CREATED << dub << "\n";

		Bureaucrat assign("assignation", 50);
		std::cout << CREATED << assign << "\n";

		assign = snorlax;
		std::cout << ASSIGN << assign << "\n";

	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// should throw exception
	try {
		// too low
		Bureaucrat snorlax("Snorlax", 0);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	try {
		// too low
		Bureaucrat snorlax("Snorlax", 151);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	try {
		// too high
		Bureaucrat snorlax("Snorlax", -150);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	try {
		// too low
		Bureaucrat snorlax("Snorlax", 420);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}
}

static void form_constructors(void)
{
	PresidentialPardonForm	president("banana");
	std::cout << CREATED << president << "\n";
	RobotomyRequestForm		robot("bleep bloop");
	std::cout << CREATED << robot << "\n";
	ShrubberyCreationForm	scrub("scrub");
	std::cout << CREATED << scrub << "\n";
}

static void	bureaucrat_modifiers(void)
{
	// should not throw
	try
	{
		Bureaucrat snorlax("Snorlax", 69);
		std::cout << CREATED << snorlax << "\n";
		
		snorlax.incrementGrade(42);
		std::cout << INCR << snorlax << "\n";

		snorlax.decrementGrade(69);
		std::cout << DECR << snorlax << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// should throw
	try {
		Bureaucrat high("high", 69);
		std::cout << CREATED << high << "\n";
		
		// too high
		high.incrementGrade(69);
		std::cout << INCR << high << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	try {
		Bureaucrat snorlax("Snorlax", 69);
		std::cout << CREATED << snorlax << "\n";
		
		// too low
		snorlax.decrementGrade(420);
		std::cout << INCR << snorlax << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}
}

static void form_modifiers(void)
{
	PresidentialPardonForm	president("banana");
	RobotomyRequestForm		robot("bleep bloop");
	ShrubberyCreationForm	scrub("scrub");
	Bureaucrat				bob("Bob", 140);

// scrub
	std::cout << "\n\n-----------shrubbery-----------\n\n";

	// not signed
	try {
		bob.executeForm(scrub);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// grade too low
	try {
		bob.signForm(scrub);
		bob.executeForm(scrub);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// should execute
	try {
		bob.incrementGrade(10);
		bob.executeForm(scrub);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

//robot
	std::cout << "\n\n-----------robot-----------\n\n";

	// not signed
	try {
		bob.incrementGrade(80);
		bob.executeForm(robot);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// grade too low
	try {
		bob.signForm(robot);
		bob.executeForm(robot);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// should execute
	try {
		bob.incrementGrade(10);
		bob.executeForm(robot);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

//president
	std::cout << "\n\n-----------president-----------\n\n";
	
	// not signed
	try {
		bob.incrementGrade(15);
		bob.executeForm(president);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// grade too low
	try {
		bob.signForm(president);
		bob.executeForm(president);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// should execute
	try {
		bob.incrementGrade(20);
		bob.executeForm(president);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}
}

static void run_test(const char* name, void (*test)())
{
	std::cout << COLOR_PINK << "\n\n---------" << name << "---------\n\n" << COLOR_RESET;
	test();
}

int main(void)
{
	run_test("Bureaucrat Constructors", bureaucrat_constructors);
	run_test("Form Constructors", form_constructors);
	run_test("Bureaucrat Modifiers", bureaucrat_modifiers);
	run_test("Form modifiers", form_modifiers);
	return (0);
}
