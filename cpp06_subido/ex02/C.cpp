/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:00:00 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 17:00:26 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "C.hpp"
#include <iostream>

C::C() {
	std::cout << "[C] constructor called." << std::endl;
}

C::~C() {
	std::cout << "[C] destructor called." << std::endl;
}
