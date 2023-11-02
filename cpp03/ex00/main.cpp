/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:05:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/01 10:53:42 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap p1("Player 1");
    ClapTrap p2("Player 2");
    
    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttackDamage());
    p2.beRepaired(5);

    p2.attack(p1.getName());
    p1.takeDamage(p2.getAttackDamage());
    p1.beRepaired(5);
    return (0);
}
/*
int main(void)
{
    ClapTrap p1("Player 1");
    ClapTrap p2("Player 2");
	p1.setAttackDamage(5);
    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttackDamage());
    p2.beRepaired(5);

	p2.setAttackDamage(4);
    p2.attack(p1.getName());
    p1.takeDamage(p2.getAttackDamage());
    p1.beRepaired(5);
    return (0);
}*/
