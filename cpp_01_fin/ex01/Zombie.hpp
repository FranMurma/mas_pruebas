/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:27:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/09 17:25:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private :
		std::string name;
		static int	zombieCount;
	public :
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		void	applyName(std::string name);
		void    announce(void);
		static int		getZombieCount();
};

Zombie*	zombieHorde( int N, std::string name );
//Zombie*	newZombie( std::string name );
//void	randomChump( std::string name );


#endif
