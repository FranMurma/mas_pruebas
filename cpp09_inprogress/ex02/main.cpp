/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:03:38 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/15 18:47:28 by frmurcia         ###   ########.fr       */
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
	std::cout << std::endl << "Before: ";
    for (int i = 1; i < argc; ++i) {
        input += argv[i];
        if (i < argc - 1) {
            input += " ";
        }
    }
	std::cout << input << std::endl;

    PmergeMe pmerge;

	size_t numSubsets;
	if (argc > 500)
		numSubsets = 7;
	if (argc > 100)
		numSubsets = 4;
	else if (argc > 20)
		numSubsets = 2;
	else
		numSubsets = 1;

			//CON LISTAS
    clock_t listTime[2];
	listTime[0] = clock();// Ponemos a 0 el cronometro para las listas
	std::list<int> sequenceList = pmerge.parseInputToList(input);//El parseo y meter el input en una std::list<int>
    // Dividir la secuencia en subconjuntos y ordenarlos
    std::list<std::list<int> > subsetsList = pmerge.splitIntoSubsequences(sequenceList, numSubsets);
    for (std::list<std::list<int> >::iterator itSubset = subsetsList.begin(); itSubset != subsetsList.end(); ++itSubset) {
        pmerge.insertionSort(*itSubset);
    }
    // Fusionar los subconjuntos ordenados dos a dos
	std::list<int> mergedList = pmerge.mergeAllSubsets(subsetsList);

    listTime[1] = clock();

    double durationList = (static_cast<double>(listTime[1] - listTime[0]) / CLOCKS_PER_SEC) * 1000;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << durationList << " ms" << std::endl;



    // PROCESAMIENTO CON VECTORES
	clock_t vectorTime[2];
	vectorTime[0]= clock();

	//Creamos el contenedor de vectores y parseamos
	std::vector<int> sequenceVector = pmerge.parseInputToVector(input);

    // Dividir la secuencia en subconjuntos y ordenarlos
    std::vector<std::vector<int> > subsetsVector = pmerge.splitIntoSubsequences(sequenceVector, numSubsets);
    for (std::vector<std::vector<int> >::iterator itSubset = subsetsVector.begin(); itSubset != subsetsVector.end(); ++itSubset) {
        pmerge.insertionVectorSort(*itSubset);
    }

    // Fusionar los subconjuntos ordenados dos a dos
	std::vector<int> mergedVector = pmerge.mergeAllVectorSubsets(subsetsVector);

	vectorTime[1] = clock();
    double durationVector = (static_cast<double>(vectorTime[1] - vectorTime[0]) / CLOCKS_PER_SEC) * 1000000;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << durationVector << " ms" << std::endl;
	if (areEqual(mergedList, mergedVector))
		std::cout << "Both sorted sequences are identical." << std::endl;
	else
		std::cerr << "Warning: Sorted sequences are not identical!" << std::endl;

	return (0);
}

