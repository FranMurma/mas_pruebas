/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:07 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/13 20:19:59 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

std::list<int> PmergeMe::parseInputToList(std::string& input) {//Metemos un string input en una lista de enteros
	std::list<int> result;
	std::istringstream iss(input);
	int	num;
	try {
		while (iss >> num) {
			if (num >= 0)
				result.push_back(num);
			else
				throw std::invalid_argument("Negatives are not allowed in the list container");
		}
		if (!iss.eof())
			throw std::invalid_argument("Invalid expression for list container");
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		result.clear(); // Limpiar el vector en caso de error
	}
	return (result);
}

std::vector<int> PmergeMe::parseInputToVector(std::string& input) {
	std::vector<int> result;
	std::istringstream iss(input);
	int	num;
	try {
		while (iss >> num) {
			if (num >= 0)
				result.push_back(num);
			else
				throw std::invalid_argument("Negatives are not allowed in the vector container");
		}
	if (!iss.eof())
		throw std::invalid_argument("Invalid expression for vector container");
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		result.clear(); // Limpiar el vector en caso de error
		std::exit(1);
	}
	return (result);
}

/*********
 * Funcion que va a tomar la lista de enteros que hemos creado en la entrada argv.
 * Recibe la lista mencionada y un entero positivo que dira en cuantas subsecuencias lo vamos a dividir
 * Nos retornara una lista de listas: std::list<std::list<int>>
 * ******/ 
std::list<std::list<int> > PmergeMe::splitIntoSubsequences(std::list<int>& elements, size_t numSubsets) {
	std::list<std::list<int> > subsets;//Llamamos subsets a la lista de listas, de momento vacia

	size_t	subsetSize = elements.size() / numSubsets;//Calculamos el tamano de cada subset
	//Una vez tenemos el numero de sublistas y el numero de elementos, 
	//podemos calcular el numero de elementos que habra en cada sublista
	size_t	remainingElements = elements.size() % numSubsets;//Y tambien tenemos el numero de elementos que sobran para el ultimo

	for (size_t i = 0; i < numSubsets; ++i) { //iteramos numero de subconjuntos
		size_t	subsetLength = subsetSize;//se inicializa con el tamaño predeterminado de cada subconjunto, que es subsetSize.
		if (remainingElements > 0) {//verificamos si hay elementos adicionales que no se han distribuido en los subconjuntos previos
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
 * Similar a splitIntoSubsequences (vid supra) pero con vectores
 * ****/
std::vector<std::vector<int> > PmergeMe::splitIntoSubsequences(std::vector<int>& elements, size_t numSubsets) {
	std::vector<std::vector<int> > subsets;

	size_t subsetSize = elements.size() / numSubsets;
	size_t remainingElements = elements.size() % numSubsets;

	std::vector<int>::iterator it = elements.begin();
	for (size_t i = 0; i < numSubsets; ++i) {
		size_t subsetLength = subsetSize + (i < remainingElements ? 1 : 0);

		std::vector<int> subset(subsetLength);
		std::copy(it, it + subsetLength, subset.begin());//copia en subset un rango de elementos desde it hasta it + subsetLength
		it += subsetLength;

		subsets.push_back(subset);
	}
	return (subsets);
}

/********
 * Funcion que ordena cada uno de las subconjuntos de enteros por separado
 *
 * **********/
void	PmergeMe::insertionSort(std::list<int>& subset) {//Recoge los subconjuntos
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

void 	PmergeMe::insertionVectorSort(std::vector<int>& subset) {
	for (size_t i = 1; i < subset.size(); ++i) {
		int currentValue = subset[i]; // El valor actual que estamos considerando
		size_t j = i; // Índice para recorrer hacia atrás

		// Recorremos hacia atrás para encontrar la posición correcta para insertar currentValue
		while (j > 0 && subset[j - 1] > currentValue) {
			subset[j] = subset[j - 1]; // Desplazamos los elementos hacia adelante
			--j; // Movemos el índice hacia atrás
		}
		
		subset[j] = currentValue; // Insertamos el valor en la posición correcta
	}
}

/******
 * Funcion para juntar y ordenar los subconjuntos pequenos
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

std::vector<int> PmergeMe::mergeVectorSubsets(const std::vector<int>& subset1, const std::vector<int>& subset2) {
	std::vector<int> mergedSubset;
	mergedSubset.reserve(subset1.size() + subset2.size()); // Reservar espacio para la fusión

	size_t i = 0, j = 0;

	// Combinar los dos subconjuntos ordenados en uno solo
	while (i < subset1.size() && j < subset2.size()) {
		if (subset1[i] < subset2[j]) {
			mergedSubset.push_back(subset1[i]);
			++i;
		}
		else {
			mergedSubset.push_back(subset2[j]);
			++j;
		}
	}

	// Agregar los elementos restantes de cualquier subconjunto que no se haya agotado
	while (i < subset1.size()) {
		mergedSubset.push_back(subset1[i]);
		++i;
	}
	while (j < subset2.size()) {
		mergedSubset.push_back(subset2[j]);
		++j;
	}
	return (mergedSubset);
}

/*****
 * Funcion para manejar todos los subsets que creamos y que ordenamos por pares en las funciones mergeSubsets
 * Son listas, abajo pondremos la de vectores.
 * ****/
std::list<int> PmergeMe::mergeAllSubsets(std::list<std::list<int> >& subsets) {
    while (subsets.size() > 1) { // Mientras haya más de un subconjunto
        // Tomar los dos primeros subconjuntos y fusionarlos
        std::list<int> merged = mergeSubsets(subsets.front(), subsets.back());
        subsets.pop_front(); // Eliminar el primer subconjunto
        subsets.pop_front(); // Eliminar el segundo subconjunto

        // Agregar el subconjunto fusionado a la lista de subconjuntos
        subsets.push_back(merged);
    }
    // Al final, queda un solo subconjunto que contiene todos los elementos fusionados
    return subsets.front();
}

/*********
 * Similar pero con vectores
 * *******/
std::vector<int> PmergeMe::mergeAllVectorSubsets(std::vector<std::vector<int> >& subsets) {
    while (subsets.size() > 1) { // Mientras haya más de un subconjunto
        // Tomar los dos primeros subconjuntos y fusionarlos
        std::vector<int> merged = mergeVectorSubsets(subsets.front(), subsets.back());
        subsets.erase(subsets.begin()); // Eliminar el primer subconjunto
        subsets.erase(subsets.begin()); // Eliminar el segundo subconjunto

        // Agregar el subconjunto fusionado al vector de subconjuntos
        subsets.push_back(merged);
    }
    // Al final, queda un solo subconjunto que contiene todos los elementos fusionados
    return subsets.front();
}
