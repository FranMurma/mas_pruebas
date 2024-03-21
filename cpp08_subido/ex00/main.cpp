/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:25:42 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/19 14:50:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::cout << "Checking with a vector myVector = {5, 20, 30, 60, 50}\n";
	std::vector<int> myVector;
	myVector.push_back(5);
	myVector.push_back(20);
	myVector.push_back(30);
	myVector.push_back(60);
	myVector.push_back(50);
	std::cout << "Looking for 10. It should give an error:\n";
    try {
		std::vector<int>::iterator it = easyfind(myVector, 10);

        // Calcular la posición del valor encontrado utilizando un puntero
        int position = it - myVector.begin();
        std::cout << "Value found in the position: " << position << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout <<  "Looking for 30. It should be found in the 2nd position::\n";
	try {
		std::vector<int>::iterator it = easyfind(myVector, 30);
		int position = it - myVector.begin();
		std::cout << "Value found in the position: " << position << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout <<  "Looking for 50. It should be found in the 4th position::\n";
	try {
		std::vector<int>::iterator it = easyfind(myVector, 50);
		int position = it - myVector.begin();
		std::cout << "Value found in the position: " << position << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
