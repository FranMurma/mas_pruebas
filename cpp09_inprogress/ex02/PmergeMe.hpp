/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:32:54 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/13 13:08:10 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime> // Biblioteca para medir el tiempo


class	PmergeMe {
	public :
		PmergeMe();
		~PmergeMe();

		//Método para ordenar la secuencia de enteros positivos usando el algoritmo de merge-insert
		void	sortSequence(std::vector<int>& sequence);

		// Función para convertir la entrada en una lista de enteros (lista // vectores)
		std::list<int> parseInputToList(std::string& input);
		// Función para convertir la entrada en un vector de enteros
		std::vector<int> parseInputToVector(std::string& input);

		// Función para dividir la lista de entrada en chunks
		std::list<std::list<int> > splitIntoSubsequences(std::list<int>& elements, size_t numSubsets);
		std::vector<std::vector<int> > splitIntoSubsequences(std::vector<int>& elements, size_t numSubsets);

		//Ordenacion de cada una de las subsecuencias por separado
		void	insertionSort(std::list<int>& subsequence);
		void	insertionVectorSort(std::vector<int>& subset);

		//Mezcla de los subconjuntos ordenados por pares
		std::list<int> mergeSubsets(const std::list<int>& subset1, const std::list<int>& subset2);
		std::vector<int> mergeVectorSubsets(const std::vector<int>& subset1, const std::vector<int>& subset2);

		//Utiliza mergeSubsets para ordenar todos los subconjuntos que obtenemos
		std::list<int> mergeAllSubsets(std::list<std::list<int> >& subsets);
		std::vector<int> mergeAllVectorSubsets(std::vector<std::vector<int> >& subsets);


	private :
		// Función privada para dividir la secuencia en subconjuntos
		template <typename Container>
		std::vector<Container> divideIntoSubsets(Container& data, size_t subsetSize);
};

#endif // PMERGEME_HPP
