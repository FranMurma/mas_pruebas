/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:31 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/01 16:07:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

Intern::Intern() {
	std::cout << "[Intern] default constructor called." << std::endl;;
}

Intern::~Intern() {
	std::cout << YELLOW << "[Intern] destructor called." << RESET << std::endl;
}

Intern::Intern(Intern const& copy) {
	if (this != &copy) {
		std::cout << "[Intern] copy constructor called." << std::endl;;
		*this = copy;
	}
}

Intern&	Intern::operator=(Intern const& copy) {
	(void) copy; //// evita advertencia de "unused parameter"
	return (*this);	
}

PPF*	Intern::makePPF(std::string formName, std::string formTarget) const {
	if (formName != "presidential pardon")
		throw IncorrectFormException();
	return (new PPF(formTarget));
}

RRF*	Intern::makeRRF(std::string formName, std::string formTarget) const {
	if (formName != "robotomy request")
		throw IncorrectFormException();
	return (new RRF(formTarget));
}

SCF*	Intern::makeSCF(std::string formName, std::string formTarget) const {
	if (formName != "shrubbery creation")
		throw IncorrectFormException();
	return (new SCF(formTarget));
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget) const {
	try {
		AForm	*form;
		form = makePPF(formName, formTarget);
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (form);
	}
	catch(const std::exception& e) {
	}
	try {
		AForm	*form;
		form = makeRRF(formName, formTarget);
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (form);
	}
	catch(const std::exception& e) {
	}
	try {
		AForm	*form;
		form = makeSCF(formName, formTarget);
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (form);
	}
	catch(const std::exception& e) {
	}
	throw IncorrectFormException();
	return (NULL);
}

const char* Intern::IncorrectFormException::what() const throw() {
	return ("Incorrect nameForm");
}
