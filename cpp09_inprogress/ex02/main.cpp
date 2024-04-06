/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:27 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/06 13:20:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "PmergeMe.hpp"

int	main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
		return (1);
    }
	std::string input = argv[1];
	PmergeMe pmerge;
	// Convertir la entrada en una lista de enteros
	std::list<int> sequenceList = pmerge.parseInputToList(input);
	std::cout << "Sequence (list): ";
	std::list<int>::const_iterator it;
	for (it = sequenceList.begin(); it != sequenceList.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

/*
	// Convertir la entrada en un vector de enteros
	std::vector<int> sequenceVector = pmerge.parseInputToVector(input);
	std::cout << "Sequence (vector): ";
	for (int num : sequenceVector) {
		std::cout << num << " ";
	}
	std::cout << std::endl;*/
	return (0);
}
