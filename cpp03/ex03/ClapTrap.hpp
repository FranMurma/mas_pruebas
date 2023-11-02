/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:21:07 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 19:18:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap{
	protected :
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other); // Constructor de copia
		ClapTrap &operator = (ClapTrap const &other);
		~ClapTrap();

		void	attack(const std::string& target); 
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void);
		unsigned int	getHitPoints(void);
		unsigned int	getEnergyPoints(void);
		unsigned int	getAttackDamage(void);
/*		unsigned int	setAttackDamage(unsigned int amount);*/
};

# endif
