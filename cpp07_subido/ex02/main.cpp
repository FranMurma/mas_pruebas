/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:04:08 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/16 19:40:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        // Creación de un objeto Array
		std::cout << "Creating an int array of 5 elements with the 1 argument constructor:\n";
        Array<int> arr1(5);

        // Inicialización del primer Array
		std::cout << "\nInicializing each array element with the value of its position + 1:\n";
        for (size_t i = 0; i < arr1.size(); ++i) {
            arr1[i] = i + 1;
        }

        // Mostrar el primer Array
        std::cout << "Array 1: ";
        for (size_t i = 0; i < arr1.size(); ++i) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        // Creación de un nuevo Array utilizando el constructor de copia
		std::cout << "\nCreating a new int array2 using the copy constructor:\n";
        Array<int> arr2(arr1);

        // Modificar el segundo Array
        std::cout << "Array 2, copy of Array 1: ";
        for (size_t i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        // Modificar el segundo Array
		std::cout << "\nModifying the int array2 with arr2[i] *= 2:\n";
        for (size_t i = 0; i < arr2.size(); ++i) {
            arr2[i] *= 2;
        }

        // Mostrar el segundo Array después de la modificación
        std::cout << "Array 2 after modification: ";
        for (size_t i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        // Mostrar el primer Array después de modificar el segundo
        std::cout << "\nArray 1 after modifying Array 2: ";
        for (size_t i = 0; i < arr1.size(); ++i) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

    } catch (std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
	}
    // Acceder a un índice fuera del rango válido para provocar la excepción
    try {
		std::cout << "\nCreating an int array of 5 elements (value 0) in order to see the out range excpt.:\n";
		Array<int> arr(5);
		std::cout << "Array: ";
		for (size_t i = 0; i < arr.size(); ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "\nTrying to access to the 10th element:\n";
        int value = arr[10]; // Esto provocará una excepción porque el índice 10 está fuera del rango válido
        std::cout << "Value obtained: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
	try {
		std::cout << std::endl;
		Array<int> arr0(0);
		std::cout << "Empty array: ";
        for (size_t i = 0; i < arr0.size(); ++i) {
            std::cout << arr0[i] << " ";
        }
        std::cout << std::endl;
	} catch (std::out_of_range& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
    return(0);
}
