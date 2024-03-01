/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:45:34 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:54 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

SCF::SCF(std::string const target) : AForm("Shrubbery", 145, 137), _target(target) {
	std::cout << "[SCF] constructor called. Creating the form 'Shrubbery'. ";
	std::cout << "Required grade to be signed: 145. Required grade to be executed: 137." << std::endl;
}

SCF::~SCF() {
	 std::cout << YELLOW << "[SCF] 'Shrubbery' destructor called." << RESET << std::endl;
}

SCF::SCF(SCF const& copy) : AForm(copy.getName(), copy.get_rGradeS(), copy.get_rGradeE()), _target(copy._target) {
	std::cout << "[SCF] copy constructor for 'Shrubbery' called\n";
}

std::string SCF::getTarget() const {
	return (this->_target);
}

SCF& SCF::operator=(SCF const& copy) {
	if (this != &copy)
	this->_target = copy._target;
	return (*this);
}

void	SCF::execute(Bureaucrat const& executor) const {//Chequea que el grado del Bureaucrat sea suficiente
	if (this->get_isSigned()) {
		if (executor.getGrade() <= 137) {
			std::ofstream file;
			file.open(this->_target + "_shrubbery");
			file << "\n\
			       _-_\n\
			    /~~   ~~\\\n\
			 /~~         ~~\\\n\
			{               }\n\
			 \\  _-     -_  /\n\
			   ~  \\ //  ~\n\
			_- -   | | _- _\n\
			  _ -  | |   -_\n\
			      // \\ \n";
	    //  realiza la limpieza del buffer de entrada
			file.flush();
			file.close();
		}
		else
			throw ExecutedFormException();
	}
	else
		throw SignFormException();
}
