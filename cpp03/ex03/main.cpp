/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:05:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 19:20:23 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap p7("Player_7");
    DiamondTrap p8("Player_8");
    p7.whoAmI();
    p8.whoAmI();

    p7.attack(p8.getName());
    p8.takeDamage(p7.getAttackDamage());
    p8.beRepaired(5);
    return (0);
}
