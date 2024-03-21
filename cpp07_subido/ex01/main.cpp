/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:08:38 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/16 12:41:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


// Función que imprime el elemento pasado como argumento
template <typename T>
void print(T element) {
    std::cout << element << " ";
}

int main() {
	{
		// Definición de un array de enteros
		int array[] = {1, 2, 3, 4, 5};
		// Longitud del array
		size_t length = sizeof(array) / sizeof(array[0]);//No sabemos cual sera el tipo previamente, hay que calcularlo

		std::cout << "Imprimimo el array (1, 2, 3, 4, 5) SIN la funcion pasando iterativamente cada elemento.\n";
		for (size_t i = 0; i < length; ++i) {
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;

		// Llamada a iter con el array, la longitud y la función de impresión
		std::cout << "\nUsando la funcion iter que llama a la funcion print para cada elemento, sinplemente escribiendo\niter(array, length, print<int>): ";
		iter(array, length, print<int>);
		std::cout << std::endl;
	}
	{
		std::cout << "\nProbamos con chars (a b c), iter(array, length, print):\n";
		char array[] = {'a', 'b', 'c'};
		size_t length = sizeof(array) / sizeof(array[0]);
		iter(array, length, print);
		std::cout << std::endl;
	}
	{
		std::cout << "\nY ahora con el array (hola que tal ?), iter(array, length, print);:\n";
		std::string array[] = {"hola", "que", "tal", "?"};
		size_t length = sizeof(array) / sizeof(array[0]);
		iter(array, length, print);
	}
	return(0);
}
