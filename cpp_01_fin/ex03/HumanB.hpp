/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:16:47 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/11 18:28:47 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB{
	private :
	std::string nameH;

	public :
	HumanB(std::string nameH);
	~HumanB();
	Weapon	*hWeapon;
	void	setWeapon(Weapon& newWeapon);
	void	attack(void);
};

# endif
