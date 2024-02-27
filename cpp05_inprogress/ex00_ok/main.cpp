/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:13:08 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/20 17:04:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
	std::cout << GREEN << "\n\nPROMOTE TEST\n" << RESET << std::endl;
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
	std::cout << GREEN << "\nDEMOTE TEST\n" << RESET << std::endl;
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

	// CONSTRUCTOR
	std::cout << GREEN << "\nCONSTRUCTOR OUT VALUES TEST" << RESET << std::endl;
	try
	{
		Bureaucrat a("Smit", -10);
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
	return 0;
}
