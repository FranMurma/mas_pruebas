/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:47:42 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/23 16:39:09 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string name = "Fran";
	int	N = 5;
	Zombie	*ZombieArray = zombieHorde(N, name);
	delete[] ZombieArray;
	return (0);
}
