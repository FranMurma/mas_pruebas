/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:04:17 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 17:16:24 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat constructor for " << this->_type << " called" << std::endl;
}

WrongCat& WrongCat::operator =(const WrongCat &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void    WrongCat::makeSound( void ) const {
	std::cout << "SSSHHHHH..." << std::endl;
}
