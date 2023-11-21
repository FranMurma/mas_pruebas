/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:36 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 17:13:06 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	if (this != &other)
	{
		*this = other;
		std::cout << "Dog constructor for " << this->_type << " called" << std::endl;
	}
}

Dog& Dog::operator =(const Dog &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void    Dog::makeSound( void ) const {
	std::cout << "WOOF!!...WOF!!..." << std::endl;
}
