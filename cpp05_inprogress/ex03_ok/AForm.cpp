/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:06:38 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/01 15:21:05 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

AForm::AForm(std::string const name, int const r_gradeS, int const r_gradeE) : _name(name), _is_signed(false), _r_gradeS(r_gradeS), _r_gradeE(r_gradeE) {

	std::cout << "[AForm] constructor called. Trying to create the form '" << this->_name << "'. Required grade to be signed: ";
	std::cout << this->_r_gradeS << ". Required grade to be executed: " << this->_r_gradeE << std::endl;;
	if (_r_gradeS < 1 || _r_gradeE < 1) {
		std::cout << RED << "Cannot!!\n";
		throw GradeTooHighException();
	}
	if (_r_gradeS > 150 || _r_gradeE > 150) {
		std::cout << RED <<  "Cannot!!\n";
		throw GradeTooLowException();
	}
}

AForm::~AForm() {
	std::cout << YELLOW << "[AForm] '" << this->_name << "' destructor called." << RESET << std::endl;
}

std::string AForm::getName() const {
	return (this->_name);
}

int	AForm::get_rGradeS() const {
	return (this->_r_gradeS);
}

int AForm::get_rGradeE() const {
	return (this->_r_gradeE);
}

bool	AForm::get_isSigned() const {
	return (this->_is_signed);
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (this->_r_gradeS >= bureaucrat.getGrade()) {
		this->_is_signed = true;
	}
	else {
		throw ExecutedFormException();
	}
}


AForm::AForm(AForm const& copy) : _name(copy._name), _is_signed(copy._is_signed), _r_gradeS(copy._r_gradeS), _r_gradeE(copy._r_gradeE) {
	std::cout << "[AForm] copy constructor for " << this ->_name << " called\n";
}

AForm& AForm::operator=(AForm const& copy) {
	if (this != &copy)
		this->_is_signed = copy._is_signed;
	return (*this);
}

const char *AForm::GradeTooHighException::what() const throw() {
   return ("AForm can't require a grade to be executed or signed over 1!\n");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("AForm can't require a grade to be executed or signed lower than 150!!\n");
}

const char  *AForm::ExecutedFormException::what() const throw() {
	return ("this form requires to be executed or signed a bureaucrat with a better grade!\n");
}

const char	*AForm::SignFormException::what() const throw() {
	return ("the form is not signed!\n");
}

std::ostream& operator <<(std::ostream& out, AForm const& obj) {
	out << obj.getName() << " (requires to be signed the grade: " << obj.get_rGradeS();
	out << ". Requires to be executed the grade: " << obj.get_rGradeE()  << ") ";
	return (out);
}
