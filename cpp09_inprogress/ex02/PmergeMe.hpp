/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:32:54 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/15 18:47:25 by frmurcia         ###   ########.fr       */
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
		PmergeMe(PmergeMe const& copy);
		PmergeMe& operator=(PmergeMe const& copy);


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

		//Usaremos esta funcion al final para comprobar que todos los elementos de la lista son exactamente iguales.
//		bool	areEqual(const std::list<int>& list1, const std::vector<int>& vec2);

};

bool    areEqual(const std::list<int>& list1, const std::vector<int>& vec2);

#endif // PMERGEME_HPP
