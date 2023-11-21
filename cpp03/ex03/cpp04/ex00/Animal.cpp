/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:03:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 17:10:46 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void) : _type("Unknown") {
	std::cout <<"Animal default constructor called" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Default destructor Animal" << std::endl;
}

//Animal::Animal(const std::string type) : type(type) {
//	std::cout <<"Type constructor for Animal called" << std::endl;
//}

Animal::Animal(const Animal &other) : _type (other._type) {
	std::cout <<"Animal constructor for " << this->_type << " called" << std::endl;
}

Animal& Animal::operator =(const Animal &other) {
	if (this != &other) {
		this->_type = other._type;
		std::cout <<"Animal " << this->_type << " copied" << std::endl;
	}
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "Something animal sound unrecognizable..." << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}
