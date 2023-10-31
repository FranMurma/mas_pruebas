/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:12:30 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/11 16:37:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	private :
	std::string Type;

	public :
	const std::string& getType(void);
	void	setType(std::string newType);
	Weapon(std::string name);
	Weapon(void);
	~Weapon(void);
};

# endif
