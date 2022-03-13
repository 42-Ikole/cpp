
#include <Bureaucrat.hpp>
#include <Form.hpp>
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
	try {
		Form n1("de nummer 1", 69, 2);
		std::cout << CREATED << n1 << "\n";

		Form copy(n1);
		std::cout << CREATED << copy << "\n";

		Form assignation = copy;
		std::cout << CREATED << assignation << "\n";
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// too high
	try {
		Form high("too high", -420, 100);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}
	
	// too high
	try {
		Form high("too high", 100, -420);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}

	// too low
	try {
		Form high("too low", 420, 100);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}
	
	// too low
	try {
		Form high("too low", 100, 420);
	} catch (const std::exception& e) {
		std::cerr << ERROR << e.what() << "\n";
	}
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
	Form woop("woop", 42, 16);
	std::cout << CREATED << woop << "\n";

	Bureaucrat bob("Bob", 43);
	std::cout << CREATED << bob << "\n";

	try {
		// grade too low
		bob.signForm(woop);

		bob.incrementGrade();

		// signs form
		bob.signForm(woop);

		// already signed
		bob.signForm(woop);

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
