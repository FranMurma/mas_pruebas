/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:58 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/27 12:24:52 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : intVal (0) {
	std::cout << "Default constructor called" <<  std::endl;
}


Fixed::Fixed(Fixed const &copy){
	std::cout << "Copy constructor called" << std::endl;
	Fixed::intVal = copy.getRawBits();
}

Fixed::~Fixed (void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator= (Fixed const &copy) {
	std::cout << "Assignation operator called" <<std::endl;
	if (this != &copy) {
		this->intVal = copy.getRawBits();
	}
    return (*this);
}

int     Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" <<std::endl;
	return (Fixed::intVal);
}

void	Fixed::setRawBits ( int const raw ) {
	std::cout <<"setRawBits member function called" <<std::endl;
	Fixed::intVal = raw;
}
