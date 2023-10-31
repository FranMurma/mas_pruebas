/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:39:12 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/11 18:05:37 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA{
	private :
	std::string nameH;
	Weapon& hWeapon;

	public :
	HumanA(std::string nameH, Weapon &hWeapon);
	~HumanA();
	void	attack(void);
};

# endif
