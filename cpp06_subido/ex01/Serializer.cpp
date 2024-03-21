/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:03:00 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/14 19:26:12 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "[Serializer] default constructor called.\n";
}

Serializer::~Serializer() {
	std::cout << "[Serializer] destructor called.\n";
}

Serializer::Serializer(Serializer const & copy) {
	(void)copy;
	std::cout << "[Serializer] copy constructor called.\n";
}

Serializer& Serializer::operator=(Serializer const& copy) {
	(void)copy;
	std::cout << "[Serializer] copy assignment operator called.\n";
	return(*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
