#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void
testBureaucrat()
{

	std::cout << std::endl << std::endl << "TESTING THE BUREAUCRAT CLASS" << std::endl;
	std::cout << "-----------------------------------------------------"  << std::endl << std::endl;
	std::cout << "PROMOTE" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	try
	{
		Bureaucrat a("Smit", 10);
		while (true)
		{
			std::cout << a;
			a.promote();
		}
	}

	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	// DEMOTE
	std::cout << "DEMOTE" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	try
	{
		Bureaucrat a("Johnson", 130);
		while (42)
		{
			std::cout << a;
			a.demote();
		}
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}



	std::cout << "BUREAUCRAT CONSTRUCTOR" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	// CONSTRUCTOR
	try
	{
		Bureaucrat a("Smit", -10);
		std::cout << "Imprimimos los valores del objeto si se ha creado: \n" << a;
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}



	try
	{
		Bureaucrat a("Johnson", 1000);
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
/*
void
testForm()
{
	std::cout << std::endl << "FORM CONSTRUCTOR" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << BLUE << "We are testing [Form] constructors without [Bureaucrat] constructors, so them should be not signed. Let's see:\n\n" << RESET;
	try
	{
		Form f("Contract", 0, 42);
		std::cout << f << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Form f("Contract", 151, 42);
		std::cout << f << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Form f("Contract", 42, 0);
		std::cout << f << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Form f("Contract", 42, 151);
		std::cout << f << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Form f1("Contract", 150, 42);
		std::cout << f1 << std::endl;
		Form f2("Contract", 1, 42);
		std::cout << f2 << std::endl;
		Form f4("Contract", 42, 150);
		std::cout << f4 << std::endl;
		Form f3("Contract", 42, 11);
		std::cout << f3 << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << RESET << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << RED << "GradeTooHighException caught: " << e.what() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	// SIGN
	std::cout << std::endl << "\n\nTESTING SIGNATURE" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	Bureaucrat b("Smit", 42);
	{
		std::cout << b << std::endl;
		Form f = Form("Contract", 43, 1);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	{
		Form f = Form("Contract", 42, 1);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	{
		Form f = Form("Contract", 41, 1);
		b.signForm(f);
		std::cout << f << std::endl;
	}

}*/

testForm(AForm& f)
{
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
	testBureaucrat();
	SCF scf("42");
	testForm(scf);
	return 0;
}
