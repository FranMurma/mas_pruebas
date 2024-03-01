/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:39:51 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/29 17:21:47 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

PPF::PPF(std::string const target) : AForm("Presidential", 25, 5), _target(target) {
	std::cout << "[PPF] constructor called. Creating the form 'Presidential'. ";
	std::cout << "Required grade to be signed: 25. Required grade to be executed: 5." << std::endl;
}

PPF::~PPF() {
	std::cout << YELLOW << "[PPF] 'Presidential' destructor called." << RESET << std::endl;
}

PPF::PPF(PPF const& copy) : AForm(copy.getName(), copy.get_rGradeS(), copy.get_rGradeE()), _target(copy._target) {
	std::cout << "[PPF] copy constructor for 'Presidential' called\n";
}

std::string PPF::getTarget() const {
	return (this->_target);
}

PPF& PPF::operator=(PPF const& copy) {
	if (this != &copy)
	this->_target = copy._target;
	return (*this);
}

void	PPF::execute(Bureaucrat const& executor) const {//Chequea que el grado del Bureaucrat sea suficiente
	if (this->get_isSigned())
	{
		if (executor.getGrade() <= 5) {
			std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
		}
		else
			throw ExecutedFormException();
	}
	else
		throw SignFormException();
}
