/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:42:01 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/21 20:23:00 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

//HumanA::HumanA(void) {
//}
HumanB::HumanB(std::string nameH) : nameH(nameH), hWeapon(nullptr) {
	std::cout << "Human B created, his name is " << nameH <<" and he is not equiped with any Weapon\n";
}

HumanB::~HumanB(void){
	std::cout << "Human B, " << nameH << ", destroyed.\n";
}
void	HumanB::setWeapon(Weapon& newWeapon){
	HumanB::hWeapon = &newWeapon;
	std::cout << nameH << " takes a weapon" << std::endl;
}

void	HumanB::attack(void){
	if (hWeapon) {
		std::cout << nameH << " attacks with " << hWeapon->getType() <<std::endl;
	}
	else {
		std::cout << nameH << " cannot attack because is  unarmed" << std::endl;
	}
}
