/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:03:38 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/13 20:19:54 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
        return 1;
    }

    std::string input;
    for (int i = 1; i < argc; ++i) {
        input += argv[i];
        if (i < argc - 1) {
            input += " ";
        }
    }

    PmergeMe pmerge;

    // Convertir la entrada en una lista de enteros
    std::list<int> sequenceList = pmerge.parseInputToList(input);
    std::vector<int> sequenceVector = pmerge.parseInputToVector(input);

    // Procesamiento con listas

	std::cout << "Before: ";
	for (std::list<int>::const_iterator it = sequenceList.begin(); it != sequenceList.end(); ++it)
		std::cout << *it << " ";
    std::cout << std::endl;
	// Definir el número de subconjuntos para la prueba
	size_t numSubsets = 1;
	if (argc < 20)
		numSubsets = 2;
	else if (argc < 100)
		numSubsets = 4;
	else
		numSubsets = 7;


    clock_t start = clock();

    // Dividir la secuencia en subconjuntos y ordenarlos
    std::list<std::list<int> > subsetsList = pmerge.splitIntoSubsequences(sequenceList, numSubsets);
    for (std::list<std::list<int> >::iterator itSubset = subsetsList.begin(); itSubset != subsetsList.end(); ++itSubset) {
        pmerge.insertionSort(*itSubset);
    }

    // Fusionar los subconjuntos ordenados dos a dos
    std::list<int> mergedSequenceList;
    std::list<std::list<int> >::iterator itMergeSubsetList = subsetsList.begin();
    while (itMergeSubsetList != subsetsList.end()) {
        mergedSequenceList = pmerge.mergeSubsets(mergedSequenceList, *itMergeSubsetList);
        ++itMergeSubsetList;
    }

    clock_t end = clock();
    double durationList = (double)(end - start) / CLOCKS_PER_SEC * 1000; // Convertir a milisegundos

    std::cout << "After: ";
    for (std::list<int>::const_iterator itNum = mergedSequenceList.begin(); itNum != mergedSequenceList.end(); ++itNum) {
        std::cout << *itNum << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << durationList << " ms" << std::endl;

    // Procesamiento con vectores

    start = clock();

    // Dividir la secuencia en subconjuntos y ordenarlos
    std::vector<std::vector<int> > subsetsVector = pmerge.splitIntoSubsequences(sequenceVector, numSubsets);
    for (std::vector<std::vector<int> >::iterator itSubset = subsetsVector.begin(); itSubset != subsetsVector.end(); ++itSubset) {
        pmerge.insertionVectorSort(*itSubset);
    }

    // Fusionar los subconjuntos ordenados dos a dos
    std::vector<int> mergedSequenceVector;
    std::vector<std::vector<int> >::iterator itMergeSubsetVector = subsetsVector.begin();
    while (itMergeSubsetVector != subsetsVector.end()) {
        mergedSequenceVector = pmerge.mergeVectorSubsets(mergedSequenceVector, *itMergeSubsetVector);
        ++itMergeSubsetVector;
    }

    end = clock();
    double durationVector = (double)(end - start) / CLOCKS_PER_SEC * 1000; // Convertir a milisegundos

/*    std::cout << "After: ";
    for (std::vector<int>::const_iterator itNum = mergedSequenceVector.begin(); itNum != mergedSequenceVector.end(); ++itNum) {
        std::cout << *itNum << " ";
    }
    std::cout << std::endl;*/
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << durationVector << " ms" << std::endl;

    return 0;
}

