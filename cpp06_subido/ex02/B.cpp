/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:58:41 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 16:59:12 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "B.hpp"
#include <iostream>

B::B() {
	std::cout << "[B] constructor called." << std::endl;
}

B::~B() {
	std::cout << "[B] destructor called." << std::endl;
}
