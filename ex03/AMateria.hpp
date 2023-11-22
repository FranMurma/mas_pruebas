/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:26:47 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 18:58:54 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class	AMateria {
	protected :
		std::string _type;

	public :
//		AMateria(void);
		virtual ~AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator =(const AMateria &other);

		std::string const &getType() const; // Devuelve el tipo de materia
		virtual AMateria* clone() const = 0;//Hacemos que sea una virtual pura (interface)
		virtual void use(ICharacter& target);
};

# endif
