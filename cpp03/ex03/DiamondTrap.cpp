/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:21:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 19:19:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap constructor for " << name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	name = name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "Copy constructor for FragTrap " << name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator =(const DiamondTrap &other) {
	if (this != &other)
	{
		name = name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap" << this->name << "  destructor called" <<::std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name: " << this->name << ". My ClapTrap mane: " << ClapTrap::name << std::endl;
}
