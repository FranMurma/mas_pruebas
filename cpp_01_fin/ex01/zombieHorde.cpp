/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:57:32 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/09 18:49:58 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
	Zombie*	ZombieArray = new Zombie[N];
	int		i = 0;
	for (i = 0; i < N; ++i)
	{
		std::string newName = name + std::to_string(i);
		ZombieArray[i].applyName(newName);
		ZombieArray[i].announce();
	}
	return (ZombieArray);
}
