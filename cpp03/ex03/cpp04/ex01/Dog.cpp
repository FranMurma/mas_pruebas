/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:36 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 19:56:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

Dog::Dog(void) : Animal(), _brain(new Brain) {
	this->_type = "Dog";
	std::cout << "[Dog]: Default constructor called" << std::endl;
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "[Brain]: Deleted" << RESET <<std::endl;
    std::cout << "[Dog]: Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	if (this != &other)
	{
		*this = other;
		std::cout << "[Dog]: Copy onstructor for " << this->_type << " called" << std::endl;
	}
}

Dog& Dog::operator =(const Dog &other) {
	if (this != &other) {
		this->_type = other._type;
		delete _brain;//Hay que borrar la memoria porque en la linea siguiente hacemos un brain nuevo que ocupa ese atributo
		this->_brain = new Brain(*other._brain);//copia profunda

	}
	return (*this);
}

void    Dog::makeSound( void ) const {
	std::cout << "WOOF!!...WOF!!..." << std::endl;
}
