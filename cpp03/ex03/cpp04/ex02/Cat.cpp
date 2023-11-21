/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:42:34 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 19:56:35 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

Cat::Cat(void) : Animal() , _brain(new Brain) {
	this->_type = "Cat";
	std::cout << "[Cat]: Default constructor called" << std::endl;
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "[Brain]: Deleted" << RESET <<std::endl;
    std::cout << "[Cat]: Destructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
	if (this != &other)
	{
		*this = other;
		std::cout << "[Cat]: Copy constructor for " << this->_type << " called" << std::endl;
	}
}

Cat& Cat::operator =(const Cat &other) {
	if (this != &other) {
		this->_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void    Cat::makeSound() const {
	std::cout << "MIIIAAAAAUUUU..." << std::endl;
}
