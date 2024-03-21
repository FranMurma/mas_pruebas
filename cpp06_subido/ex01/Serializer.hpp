/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:09:48 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/14 18:10:05 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cmath>
#include <limits>
#include <string>
#include <iostream>
#include <stdint.h>

typedef	struct s_Data { // Definición de la estructura Data
	std::string	_name;
	int			_value;
	void		*p;
}	Data;

class	Serializer {
	private :
		Serializer();
		~Serializer();
		Serializer(Serializer const & copy);
		Serializer & operator=(Serializer const& copy);
	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
