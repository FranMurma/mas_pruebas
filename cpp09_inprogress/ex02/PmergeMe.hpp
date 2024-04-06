/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:32:54 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/04 15:10:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>

class	PmergeMe {
	public :
		PmergeMe();
		~PmergeMe();

		//Método para ordenar la secuencia de enteros positivos usando el algoritmo de merge-insert
		void	sortSequence(std::vector<int>& sequence);

		// Función para convertir la entrada en una lista de enteros
		std::list<int> parseInputToList(const std::string& input);

		// Función para convertir la entrada en un vector de enteros
		std::vector<int> parseInputToVector(const std::string& input);

	private :
		// Función privada para dividir la secuencia en subconjuntos
		template <typename Container>
		std::vector<Container> divideIntoSubsets(const Container& data, size_t subsetSize);
};

#endif // PMERGEME_HPP
