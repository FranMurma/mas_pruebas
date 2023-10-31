/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:17:41 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/11 16:38:42 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void){
	return (Type);
}

void	Weapon::setType(std::string newType){
	Weapon::Type = newType;
}

Weapon::Weapon(std::string name)
{
    Weapon::Type = name;
}

Weapon::Weapon(){
}

Weapon::~Weapon(){
}
