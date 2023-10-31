/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:41:34 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/11 18:10:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

//HumanA::HumanA(void) {
//}

HumanA::HumanA(std::string nameH, Weapon &hWeapon) : nameH(nameH), hWeapon(hWeapon){
	std::cout << "Human A created, his name is " << nameH <<" and he is equiped with ";
	std::cout <<hWeapon.getType() <<std::endl;
	
}

HumanA::~HumanA(void){
	std::cout << "Human A, " << nameH << ", destroyed.\n";
}

void	HumanA::attack(void){
	std::cout << nameH << " attacks with " << hWeapon.getType() <<std::endl;
}
