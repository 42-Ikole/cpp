
#include <Bureaucrat.hpp>
#include <string>
#include <iostream>

void	construction(void)
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
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}

	// should throw exception
	try {
		// too low
		Bureaucrat snorlax("Snorlax", 0);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}

	try {
		// too low
		Bureaucrat snorlax("Snorlax", 151);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}

	try {
		// too high
		Bureaucrat snorlax("Snorlax", -150);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}

	try {
		// too low
		Bureaucrat snorlax("Snorlax", 420);
		std::cout << CREATED << snorlax << "\n";
	}
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}
}

static void	modifiers(void)
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
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}

	// should throw
	try {
		Bureaucrat snorlax("Snorlax", 69);
		std::cout << CREATED << snorlax << "\n";
		
		// too high
		snorlax.incrementGrade(69);
		std::cout << INCR << snorlax << "\n";
	}
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}

	try {
		Bureaucrat snorlax("Snorlax", 69);
		std::cout << CREATED << snorlax << "\n";
		
		// too low
		snorlax.decrementGrade(420);
		std::cout << INCR << snorlax << "\n";
	}
	catch (std::exception& e) {
		std::cout << ERROR << e.what() << "\n";
	}
}

static void run_test(const char* name, void (*test)())
{
	std::cout << COLOR_PINK << "\n\n---------" << name << "---------\n\n" << COLOR_RESET;
	test();
}

int main(void)
{
	run_test("Constructors", construction);
	run_test("Modifiers", modifiers);
	return (0);
}
