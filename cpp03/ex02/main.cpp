/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:05:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 17:02:37 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << std::endl;

    FragTrap p5("Player 5");
    FragTrap p6("Player 6");

    p5.attack(p6.getName());
    p6.takeDamage(p5.getAttackDamage());
    p6.beRepaired(5);
    p5.highFivesGuys();
    p6.highFivesGuys();
    return (0);
}
