/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:49:15 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 19:18:12 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private :
		std::string name;

	public :
		DiamondTrap(std::string name);
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator =(const DiamondTrap& other);
		~DiamondTrap(void);

		using   ScavTrap::attack;
		void	whoAmI();
};

# endif
