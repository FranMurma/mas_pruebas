/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:30 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/14 19:48:22 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

/*
int main()
{
    Data        data;
    uintptr_t   *raw;

    data._name = "Hello";
    data._value = 42;
    data.p = &data._value;

    std::cout << "Data Before Serialization: " << std::endl;
    std::cout << "data._name: " << data._name << std::endl;
    std::cout << "data._value: " << data._value << std::endl;
    std::cout << "data.p: " << data.p << std::endl;

    raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;

    Data    *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << ptr << std::endl;

    std::cout << "Data After Deserialization: " << std::endl;
    std::cout << "Deserialized data->_name: " << ptr->_name << std::endl;
    std::cout << "Deserialized data->n: " << ptr->_value << std::endl;
    std::cout << "Deserialized data->p: " << ptr->p << std::endl;

    return ( 0 );
}*/

int main(void)
{
	Data		*ptr;
	Data		*newPtr;
	uintptr_t	raw;
	int			number;
	std::string	name;

	number = 42;
	name = "Forty-two";
	ptr = new Data;
	ptr->_name = name;
	ptr->_value = number;
	ptr->p = &number;
	std::cout << "Number used is " << number << std::endl;
	std::cout << "[BEFORE Serialization] " \
				<< "Data *ptr stats -> ptr: " << ptr << std::endl \
				<< " && ptr->_name: " << ptr->_name << std::endl \
				<< " && ptr->_value: " << ptr->_value << std::endl \
				<< " && ptr->_p: " << ptr->p << std::endl \
				<< " && *(reinterpret_cast<int*>(ptr->p)): " << *(reinterpret_cast<int*>(ptr->p)) << std::endl \
				<< std::endl;
	raw = Serializer::serialize( ptr );
	std::cout << "We have obtained the unsigned integer type uintptr_t (*raw): " \
				<< raw << std::endl;

	newPtr = Serializer::deserialize( raw );
	std::cout << "Now, from this uintptr_t (*raw), " << raw << ", we get...:" << std::endl;
	std::cout << "[AFTER Serialization] "\
				<< " Data *newPtr stats -> ptr: " << newPtr << std::endl\
				<< " && newPtr->_name: " << newPtr->_name << std::endl\
				<< " && newPtr->_value: " << newPtr->_value << std::endl\
				<< " && newPtr->p: " << newPtr->p << std::endl\
				<< " && *(reinterpret_cast<int*>(newPtr->ptr)): " << *(reinterpret_cast<int*>(newPtr->p)) << std::endl \
				<< std::endl;
	delete ptr;
	return ( 0 );
}
