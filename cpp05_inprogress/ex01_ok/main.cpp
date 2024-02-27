#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

}

int main()
{
	testBureaucrat();
	testForm();
	return 0;
}
