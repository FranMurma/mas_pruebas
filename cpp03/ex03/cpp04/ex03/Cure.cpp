/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:59:43 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 19:49:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "[Cure] default constructor called" << std::endl;
}

Cure::~Cure(void) {
	std::cout << "[Cure] destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other)
		AMateria::operator=(other);//Usamos el operador de copia de AMateria, asi nos vale si ampliamos los atributos, SOLO har falta ampliarlos en AMateria y el resto de clases los recogera en eloperador de copia y, por tanto, en el constructor de copia
	return (*this);
}

Cure::Cure(const Cure &type) : AMateria(type) {
	if (this != &type)
		*this = type;
	std::cout << "[Cure] copied" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
