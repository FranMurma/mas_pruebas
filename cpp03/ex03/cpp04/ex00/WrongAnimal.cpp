/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:59:47 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 17:59:13 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Unknown") {
	std::cout <<"WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	if (this != &other)
	{
		*this = other;
		std::cout <<"WrongAnimal constructor for " << this->_type << " called" << std::endl;
	}
}

WrongAnimal& WrongAnimal::operator =(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Something animal unrecognozible and wrong..." << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}
