/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:54:43 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 17:00:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "A.hpp"
#include <iostream>

A::A() {
	std::cout << "[A] constructor called." << std::endl;
}

A::~A() {
	std::cout << "[A] destructor called." << std::endl;
}
