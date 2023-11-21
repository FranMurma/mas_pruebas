/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:42:34 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 17:13:27 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
	if (this != &other)
	{
		*this = other;
		std::cout << "Cat constructor for " << this->_type << " called" << std::endl;
	}
}

Cat& Cat::operator =(const Cat &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void    Cat::makeSound() const {
	std::cout << "MIIIAAAAAUUUU..." << std::endl;
}
