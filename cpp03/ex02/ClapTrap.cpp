/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:24:41 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 17:15:38 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructores
ClapTrap::ClapTrap(void) {
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout <<"Constructor for ClapTrap " << name << " called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) { //Constructor de copia
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout <<"Copy Constructor for ClapTrap " << name << " called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor for ClapTrap " << name << " called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else {
		std::cout << name << " can't attack because they have no hit points or energy!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		return ;
	}
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " has received " << amount << " points of damage." << std::endl;
	std::cout << "ClapTrap " << name << " has a total of " << hitPoints << " points of health." << std::endl;
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't resist. He is destroyed." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints > 0 && energyPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " has been repaired.";
		std::cout <<" He has now " << hitPoints	<< " points of health." << std::endl;
	}
	else if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot be repaired because he has not more energy points.\n";
	}
}

unsigned int	ClapTrap::getHitPoints(void) {
	return this->hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) {
	return this->energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) {
	return this->attackDamage;
}


std::string ClapTrap::getName(void)
{
	return this->name;
}
/*
unsigned int    ClapTrap::setAttackDamage(unsigned int amount) {
	this->attackDamage = amount;
	return this->attackDamage;
}*/

