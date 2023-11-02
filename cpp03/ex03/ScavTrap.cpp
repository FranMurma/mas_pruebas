/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:32:09 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/01 12:36:30 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->name =  name;
    std::cout << "ScavTrap constructor for " << name << " called" << std::endl;
    // Initializations specific to ScavTrap
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) { //Constructor de copia
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout <<"Copy Constructor " << name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator = (ScavTrap const &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap desctructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else {
		std::cout << name << " can't attack because they have no hit points or energy!" << std::endl;
	}
}

// Implement the rest of the member functions (e.g., copy constructor, assignment operator)

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
