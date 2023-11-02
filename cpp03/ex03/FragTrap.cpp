/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:45:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 17:15:34 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	std::cout << "FragTrap constructor for " << name << " called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "Copy constructor for FragTrap " << name << " called" << std::endl;
}

FragTrap &FragTrap::operator = (FragTrap const &other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "FragTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;}
	else {
		std::cout << name << " can't attack because they have no hit points or energy!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " says: 'Give me a high five, guys!'" << std::endl;
}
