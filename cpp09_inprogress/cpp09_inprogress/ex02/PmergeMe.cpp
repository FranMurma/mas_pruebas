/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:07 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/08 19:46:38 by frmurcia         ###   ########.fr       */
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
			throw std::runtime_error("Negatives are not allowed");
	}
	if (!iss.eof())
		throw std::runtime_error("Invalid expression");
	return (result);
}

/*********
 * Funcion que va a tomar la lista de enteros que hemos creado en la entrada argv.
 * Recibe la lista mencionada y un entero positivo que dira en cuantas subsecuencias lo vamos a dividir
 * Nos retornara una lista de listas: std::list<std::list<int>>
 * ******/ 
std::list<std::list<int> > PmergeMe::splitIntoSubsets(std::list<int>& elements, size_t numSubsets) {
	std::list<std::list<int> > subsets;//Llamamos subsets a la lista de listas, de momento vacia

	size_t	subsetSize = elements.size() / numSubsets;//Calculamos el tamano de cada subset
	//Una vez tenemos el numero de sublistas y el numero de elementos, 
	//podemos calcular el numero de elementos que habra en cada sublista
	size_t	remainingElements = elements.size() % numSubsets;//Y tambien tenemos el numero de elementos que sobran para el ultimo

	for (size_t i = 0; i < numSubsets; ++i) { //iteramos numero de subconjuntos
		size_t	subsetLength = subsetSize;//se inicializa con el tamaño estandar de subset
		if (remainingElements > 0) {//verificamos si hay elementos adicionales 
			subsetLength++;
			remainingElements--;
		}
		std::list<int> subset;//Creamos otro subconjunto vacio
		for (size_t j = 0; j < subsetLength; ++j) {
			if (!elements.empty()) {//Comprobamos que queden numeros
				subset.push_back(elements.front());//// Extrae el primer elemento de la lista de entrada y lo agrega al subconjunto
				elements.pop_front();//// Elimina el elemento agregado de la lista de entrada
			}
		}
		subsets.push_back(subset);// Agrega el subconjunto creado al vector de subconjuntos
	}
	return (subsets);
}

/********
 * Funcion que ordena cada uno de las subconjuntos de enteros por separado
 *
 * **********/
void PmergeMe::insertionSort(std::list<int>& subset) {//Recoge los subconjuntos
    std::list<int>::iterator itCurrent, itNext;//Definimos dos iteradores, uno apunta al actual subconjunto y otro al siguiente
    for (itCurrent = subset.begin(); itCurrent != subset.end(); ++itCurrent) {//Itearmos por toddo el actual subset
        int currentValue = *itCurrent;//Definimos un entero currentValue, que igualamos con el valor del iterador
        itNext = itCurrent;//Igualamos el iterador itNext al actual en cada paso.
        while (itNext != subset.begin() && *(--itNext) > currentValue) {
			//mientras no estemos al principio del subconjunto, si el previo es mayor
            std::iter_swap(itNext, std::next(itNext));//Hacemos un swap
        }
    }
}

/******
 * Funcion para untar y ordenar los subconjuntos pequenos
 *
 * *****/
std::list<int> PmergeMe::mergeSubsets(const std::list<int>& subset1, const std::list<int>& subset2) {
    std::list<int> mergedSubset;

    // Obtener iteradores para recorrer los dos subconjuntos ordenados
    std::list<int>::const_iterator it1 = subset1.begin();
    std::list<int>::const_iterator it2 = subset2.begin();

    // Combinar los dos subconjuntos ordenados en uno solo
    while (it1 != subset1.end() && it2 != subset2.end()) {
        if (*it1 < *it2) {
            mergedSubset.push_back(*it1);
            ++it1;
        } else {
            mergedSubset.push_back(*it2);
            ++it2;
        }
    }

    // Agregar los elementos restantes de cualquier subconjunto que no se haya agotado
    while (it1 != subset1.end()) {
        mergedSubset.push_back(*it1);
        ++it1;
    }

    while (it2 != subset2.end()) {
        mergedSubset.push_back(*it2);
        ++it2;
    }

    return mergedSubset;
}


