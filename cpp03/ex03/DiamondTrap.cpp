/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:21:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/04 12:22:19 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DefaultName") {
	this->name = "DefaultName";
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "attackDamage = " << this->attackDamage << std::endl;
	std::cout << "DiamondTrap default constructor for " << name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap constructor for " << name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "Copy constructor for DiamondTrap " << name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator =(const DiamondTrap &other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->name << "  destructor called" <<::std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name: " << this->name << ". My ClapTrap mane: " << ClapTrap::name << std::endl;
}
