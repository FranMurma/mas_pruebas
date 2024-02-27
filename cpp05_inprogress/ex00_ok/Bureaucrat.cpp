/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:05:51 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/20 17:04:47 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	std::cout << "[Bureaucat] constructor called. Trying to create Bureaucrat " << this->_name;
	std::cout << ", grade " << this->_grade << std::endl;;
	if (grade < 1) {
		std::cout << RED << "Cannot!!\n";
		throw GradeTooHighException();
	}
	if (grade > 150) {
		std::cout << RED <<  "Cannot!!\n";
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "[Bureaucrat] destructor called." << RESET << std::endl;
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy) {
	if (this != &copy)
		*this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& copy) {
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

void	Bureaucrat::promote() {
	if (this->getGrade() > 1) { 
		std::cout << "[Promoting Bureaucrat] " << this->_name << " from grade ";
		std::cout << this->getGrade() << ", to grade " << this->getGrade() - 1 << std::endl;
		_grade--;
	}	
	else {
		std::cout << "Trying to promote Bureaucrat " << this->_name << " from grade ";
		std::cout << this->getGrade() << ", to grade " << this->getGrade() - 1 << std::endl;
		std::cout << RED <<  "Cannot!!" << std::endl;
		throw GradeTooHighException();
	}
}

void	Bureaucrat::demote() {
	if (this->getGrade() < 150) {
		std::cout << "[Demoting Bureaucrat] " << this->_name << " from grade ";
		std::cout << this->_grade << ", to grade " << this->_grade + 1 << std::endl;
		this->_grade++;
	}
	else {
		std::cout << "Trying to demote Bureaucrat " << this->_name << " from grade ";
		std::cout << this->_grade << ", to grade " << this->_grade + 1 << std::endl;
		std::cout << RED << "Cannot!!" << std::endl;
		throw GradeTooLowException();
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
   return ("Bureaucrat can't get a grade over 1!\n");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat can't get a grade lower than 150!!\n");
}

std::ostream& operator <<(std::ostream& out, Bureaucrat const& obj) {
	out << GREEN << obj.getName() << " has the grade: " << obj.getGrade() << RESET << std::endl;
	return (out);
}
