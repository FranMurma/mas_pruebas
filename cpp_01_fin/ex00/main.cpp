/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:47:42 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/23 16:25:26 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string name = "Fran";
	Zombie *FirstZombie = new Zombie(name);
	FirstZombie->announce();
	delete FirstZombie;
	randomChump("Rober");
	return (0);
}
