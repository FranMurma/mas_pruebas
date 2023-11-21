/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:30:24 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 19:49:06 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "[Ice] default constructor called" << std::endl;
}

Ice::~Ice(void) {
	std::cout << "[Ice] destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other)
		AMateria::operator=(other);//Usamos el operador de copia de AMateria, asi nos vale si ampliamos los atributos, SOLO hara falta ampliarlos en AMateria y el resto de clases los recogera en el operador de copia y, por tanto, en el constructor de copia
	return (*this);
}

Ice::Ice(const Ice &type) : AMateria(type) {
	if (this != &type)
		*this = type;
	std::cout << "[Ice] copied" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
