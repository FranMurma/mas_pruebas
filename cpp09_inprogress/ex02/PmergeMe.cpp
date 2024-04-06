/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:07 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/06 13:20:31 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

std::list<int> PmergeMe::parseInputToList(const std::string& input) {//Metemos un string input en una lista de enteros
	std::list<int> result;
	std::istringstream iss(input);
	int	num;
	while (iss >> num) {
		if (num >= 0)
			result.push_back(num);
		else
			std::cerr << "Negatives are not allowed" << std::endl;
	}
	if (!iss.eof()) {
		std::cerr << "Invalid expression" << std::endl;
	}
	return (result);
}

/*********
 * Funcion que va a tomar la lista de enteros que hemos creado en la entrada argv.
 * Recibe la lista mencionada y un entero positivo que dira en cuantas subsecuencias lo vamos a d.
 * Nos retornara una lista de listas: std::list<std::list<int>>
 * ******/ 
std::list<std::list<int>> splitIntoSubsequences(const std::list<int>& numbers, size_t numSubsets) {
	std::list<std::list<int>> subsets;//Llamamos subsets a la lista de listas

	size_t	subsetSize = numbers.size() / numSubsets;
	//Una vez tenemos el numero de sublistas y el numero de elementos, 
	//podemos calcular el numero de elementos que habra en cada sublista
	size_t	remainingElements = numbers.size() % numSubsets;//Y tambien tenemos el numero de elementos que sobran para el ultimo

	std::list<int>::const_iterator it = numbers.begin();//Creamos un iterador que inicializamos al comienzo de la lista numbers.
	for (size_t i = 0; i < numSubsets; ++i) { //iteramos numero de subconjuntos
		size_t	subsetLength = subsetSize;//se inicializa con el tamaño predeterminado de cada subconjunto, que es subsetSize.
		if (remainingElements > 0) {//verificamos si hay elementos adicionales que no se han distribuido en los subconjuntos previos
			subsetLength++;
			remainingElements--;
		}
		std::list<int> subset(it, it);
		subsets.push_back(subset);
		for (size_t j = 0; j < subsetLength; ++j) {
			++it;
		}
	}
	return (subsets);
}



/*
std::vector<std::list<int>> splitIntoSubsequences(const std::list<int>& list, size_t subsequenceSize) {
	std::vector<std::list<int>> subsequences;
	typename std::list<int>::const_iterator it = list.begin();
	while (it != list.end()) {
		std::list<int> subsequence;
		for (size_t i = 0; i < subsequenceSize && it != list.end(); ++i, ++it) {
			subsequence.push_back(*it);
		}
		subsequences.push_back(subsequence);
	}
	return (subsequences);
}*/


/*
std::vector<int> PmergeMe::parseInputToVector(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);
    int num;

    while (iss >> num) {
        result.push_back(num);
    }

    return result;
}
*/
