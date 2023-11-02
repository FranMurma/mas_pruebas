/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:05:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/01 12:37:43 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap p3("Player 3");
    ScavTrap p4("Player 4");

    p3.attack(p4.getName());
    p4.takeDamage(p3.getAttackDamage());
    p4.beRepaired(5);
    p3.guardGate();
    p4.guardGate();
    return (0);
}
