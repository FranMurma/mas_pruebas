#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void
tesBureaucrat()
{
	// PROMOTE
	try
	{
		Bureaucrat a("Smit", 10);
		while (42)
		{
			a.promote();
			std::cout << a << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// DEMOTE
	try
	{
		Bureaucrat a("Smit", 130);
		while (42)
		{
			a.demote();
			std::cout << a << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// CONSTRUCTOR
	try
	{
		Bureaucrat a("Smit", -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat a("Smit", 1000);
		while (42)
		{
			a.promote();
			std::cout << a << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void
testForm(AForm& f)
{

	std::cout << YELLOW << "\n\n\nBUREAUCRATS CREATION. Grades: 5, 6, 25, 26, 45, 46, 72, 73, 137, 138, 145, 146\n" << RESET << std::endl;
	Bureaucrat b1("John_5", 5);
	Bureaucrat b2("John_6", 6);
	Bureaucrat b3("John_25", 25);
	Bureaucrat b4("John_26", 26);
	Bureaucrat b5("John_45", 45);
	Bureaucrat b6("John_46", 46);
	Bureaucrat b7("John_72", 72);
	Bureaucrat b8("John_73", 73);
	Bureaucrat b9("John_137", 137);
	Bureaucrat b10("John_138", 138);
	Bureaucrat b11("John_145", 145);
	Bureaucrat b12("John_146", 146);

	std::cout << YELLOW <<  "PRINTING BUREAUCRATS INFO. Grades: 5, 6, 25, 26, 45, 46, 72, 73, 137, 138, 145, 146\n" << RESET << std::endl;
	std::cout << f << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;
	std::cout << b6 << std::endl;
	std::cout << b7 << std::endl;
	std::cout << b8 << std::endl;
	std::cout << b9 << std::endl;
	std::cout << b10 << std::endl;
	std::cout << b11 << std::endl;
	std::cout << b12 << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW <<  "BUREAUCRATS EXECUTING WITHOUT SIGNATURE. Grades: 5, 6, 25, 26, 45, 46, 72, 73, 137, 138, 145, 146\n" << RESET << std::endl;
	// EXEC NOT SIGNED
	b12.executeForm(f);
	b11.executeForm(f);
	b10.executeForm(f);
	b9.executeForm(f);
	b8.executeForm(f);
	b7.executeForm(f);
	b6.executeForm(f);
	b5.executeForm(f);
	b4.executeForm(f);
	b3.executeForm(f);
	b2.executeForm(f);
	b1.executeForm(f);

	std::cout << std::endl;

	 std::cout << YELLOW <<  "SIGNING FORMS. Bureaucrat grades: 5, 6, 25, 26, 45, 46, 72, 73, 137, 138, 145, 146\n" << RESET << std::endl;
	// SIGN
	b12.signForm(f);
	b11.signForm(f);
	b10.signForm(f);
	b9.signForm(f);
	b8.signForm(f);
	b7.signForm(f);
	b6.signForm(f);
	b5.signForm(f);
	b4.signForm(f);
	b3.signForm(f);
	b2.signForm(f);
	b1.signForm(f);

	std::cout << std::endl;

	 std::cout << YELLOW <<  "BUREAUCRATS EXECUTING FORMS SIGNED. Bureaucrat grades: 5, 6, 25, 26, 45, 46, 72, 73, 137, 138, 145, 146\n" << RESET << std::endl;

	// EXEC SIGNED
	b12.executeForm(f);
	b11.executeForm(f);
	b10.executeForm(f);
	b9.executeForm(f);
	b8.executeForm(f);
	b7.executeForm(f);
	b6.executeForm(f);
	b5.executeForm(f);
	b4.executeForm(f);
	b3.executeForm(f);
	b2.executeForm(f);
	b1.executeForm(f);

}

int main()
{
//	tesBureaucrat();
	SCF scf("42");
	testForm(scf);
	std::cout << std::endl;
	std::cout << std::endl;
	RRF rrf("Drop");
	testForm(rrf);
	std::cout << std::endl;
	std::cout << std::endl;
/*	PPF ppf("Drop");
	testForm(ppf);*/
	return 0;
}
