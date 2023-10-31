/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:27:54 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/07 19:21:37 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private :
		std::string name;
	public :
		Zombie(std::string name);
		~Zombie(void);
		void    announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif
