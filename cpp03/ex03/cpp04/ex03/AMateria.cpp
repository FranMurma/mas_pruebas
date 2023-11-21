/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:42:05 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 18:59:01 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

//interfaz o clase base abstracta para los diferentes tipos de materias en la aplicación
AMateria::~AMateria(void) {
	std::cout << "[AMateria] default destructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type){
	std::cout << "[AMateria] constructor " << this->_type << " for AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	if (this != &other)
		*this = other;
	std::cout << "[AMateria] copied" << std::endl;
}

AMateria &AMateria::operator =(const AMateria &other) {
	this->_type = other._type;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

AMateria* AMateria::clone() const
{
	return (AMateria*)this;// creamos una nueva AMateria y devolvemos un puntero a ella. Se usa implicitamente el cconstructor de copia (hacemos copia profunda)
}   

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
} 
