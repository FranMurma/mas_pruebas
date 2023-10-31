/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:43:33 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/23 16:30:13 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void)
{
	std::cout <<"My name is " <<this->name << ": there's no more braiiiiiiinnnzzzZ, I'm dead now...\n";
}

void Zombie::announce(void)
{
	std::cout <<this->name << ": BraiiiiiiinnnzzzZ...\n";
}
