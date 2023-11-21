/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:40:06 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 18:25:45 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter {
	private :
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria**	_ground;
		int			_groundSize;

	public :
		Character(std::string const &name);
		~Character(void);
		Character(const Character &other);
		Character &operator=(const Character &other);
		
		virtual std::string const &getName() const;//Devuelve el nombre del personaje
		virtual void equip(AMateria* m);//Equipa una materia en el inventario del personaje
		virtual void unequip(int idx);//Desequipa la materia en la posición idx del inventario
		virtual void use(int idx, ICharacter& target);//Utiliza la materia en la posición idx del inventario en el objetivo target.
};

# endif
