/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:27 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/08 19:46:42 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "PmergeMe.hpp"

int	main(int argc, char** argv) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
		return (1);
    }

	std::string input;
    for (int i = 1; i < argc; ++i) {
        input += argv[i];
        if (i < argc - 1) {
            input += " ";
        }
    }

	// Medir el tiempo de inicio

	PmergeMe pmerge;
	// Convertir la entrada en una lista de enteros
	std::list<int> sequenceList = pmerge.parseInputToList(input);
	std::cout << "Before: ";
	clock_t start = clock();
	std::list<int>::const_iterator it;
	for (it = sequenceList.begin(); it != sequenceList.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	

    size_t numSubsets = 2; // Definir el número de subconjuntos para la prueba
    std::list<std::list<int> > subsets = pmerge.splitIntoSubsequences(sequenceList, numSubsets);

    std::list<std::list<int> >::iterator itSubset;
    for (itSubset = subsets.begin(); itSubset != subsets.end(); ++itSubset) {
		pmerge.insertionSort(*itSubset); // Ordenar el subconjunto con inserción
        std::list<int>::const_iterator itNum;
	}

	// Fusionar los subconjuntos ordenados dos a dos
	std::list<int> mergedSequence;
	std::list<std::list<int> >::iterator itMergeSubset = subsets.begin();
	while (itMergeSubset != subsets.end()) {
		mergedSequence = pmerge.mergeSubsets(mergedSequence, *itMergeSubset); // Fusionar el subconjunto actual con la secuencia fusionada actual
		++itMergeSubset; // Pasar al siguiente subconjunto
	}

	// Imprimir la última lista ordenada
	std::cout << "\nAfter:";
	for (std::list<int>::const_iterator itNum = mergedSequence.begin(); itNum != mergedSequence.end(); ++itNum) {
		std::cout << *itNum << " ";
	}
	std::cout << std::endl;
	
	//Parar el reloj
	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000; // Convertir a microsegundos

	// Mostrar el tiempo transcurrido	
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list = " << duration << std::endl;

	return (0);
}
