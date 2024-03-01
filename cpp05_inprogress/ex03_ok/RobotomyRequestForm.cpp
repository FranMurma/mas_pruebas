/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:14:27 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/29 17:53:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

RRF::RRF(std::string const target) : AForm("Robotomy", 72, 45), _target(target) {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cout << "[RRF] constructor called. Creating the form 'Robotomy'. ";
	std::cout << "Required grade to be signed: 72. Required grade to be executed: 45." << std::endl;
}

RRF::~RRF() {
	 std::cout << YELLOW << "[RRF] 'Robotomy' destructor called." << RESET << std::endl;
}

RRF::RRF(RRF const& copy) : AForm(copy.getName(), copy.get_rGradeS(), copy.get_rGradeE()), _target(copy._target) {
	std::cout << "[RRF] copy constructor for 'Robotomy' called\n";
}

std::string RRF::getTarget() const {
	return (this->_target);
}

RRF& RRF::operator=(RRF const& copy) {
	if (this != &copy)
	this->_target = copy._target;
	return (*this);
}

void	RRF::execute(Bureaucrat const& executor) const {//Chequea que el grado del Bureaucrat sea suficiente
	if (this->get_isSigned())
	{
		if (executor.getGrade() <= 45) {
			std::cout << "Executing " << this->_target << std::endl;
			std::cout << YELLOW << "* Drilling noises *" << RESET << std::endl;
			std::cout << "The robotomy for " << this->_target << " was a " << (std::rand() % 2 ? GREEN "success.\n" : RED "failure.\n") << std::endl;
		}
		else
			throw ExecutedFormException();
	}
	else
		throw SignFormException();
}
