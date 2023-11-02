/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:45:43 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/02 17:01:32 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap : virtual public ClapTrap {
	public :
	   FragTrap();
	   FragTrap(std::string name);
	   FragTrap(const FragTrap& other);
	   FragTrap& operator=(const FragTrap& other);
	   ~FragTrap();
	   
	   void attack(const std::string& target);
	   void highFivesGuys(void);
};

# endif
