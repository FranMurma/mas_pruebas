/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:06:38 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/21 17:23:14 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

Form::Form(std::string const name, int const r_gradeS, int const r_gradeE) : _name(name), _is_signed(false), _r_gradeS(r_gradeS), _r_gradeE(r_gradeE) {

	std::cout << "[Form] constructor called. Trying to create the form '" << this->_name << "'. Required grade to be signed: ";
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

Form::~Form() {
	std::cout << YELLOW << "[Form] '" << this->_name << "' destructor called." << RESET << std::endl;
}

std::string Form::getName() const {
	return (this->_name);
}

int	Form::get_rGradeS() const {
	return (this->_r_gradeS);
}

int Form::get_rGradeE() const {
	return (this->_r_gradeE);
}

bool	Form::get_isSigned() const {
	return (this->_is_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (this->_r_gradeS >= bureaucrat.getGrade())
		this->_is_signed = true;
}

Form::Form(Form const& copy) : _name(copy._name), _is_signed(copy._is_signed), _r_gradeS(copy._r_gradeS), _r_gradeE(copy._r_gradeE) {
	std::cout << "[Form] copy constructor for " << this ->_name << " called\n";
}

Form& Form::operator=(Form const& copy) {
	if (this != &copy)
		this->_is_signed = copy._is_signed;
	return (*this);
}


const char *Form::GradeTooHighException::what() const throw() {
   return ("Form can't require a grade to be executed or signed over 1!\n");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Form can't require a grade to be executed or signed lower than 150!!\n");
}

std::ostream& operator <<(std::ostream& out, Form const& obj) {
	out << obj.getName() << ". Requires to be signed the grade: " << obj.get_rGradeS();
	out << ". Requires to be executed the grade: " << obj.get_rGradeE()  << RESET << std::endl;
	out << GREEN << "It " << (obj.get_isSigned() ? "is " : "is not ") << "signed" << RESET << std::endl;
	return (out);
}
