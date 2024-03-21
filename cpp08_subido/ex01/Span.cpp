/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:12:20 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/19 18:35:34 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(unsigned int capacity) : capacity(capacity) {
	std::cout << "[Span] constructor called, max capacity " << this->capacity << " elements." << std::endl;
}

Span::~Span() {
	std::cout << "[Span] destructor called" << std::endl;
}

Span::Span(Span const& copy) {
	if (this != &copy)
		*this = copy;
}

Span& Span::operator=(Span const& copy) {
	if (this != &copy) {
		this->capacity = copy.capacity;
		this->elements = copy.elements;
	}
	return (*this);
}

void	Span::addNumber(int number) {
	if (elements.size() >= capacity)
		throw FullVectorException();
	elements.push_back(number);
	std::cout << "[Span] added number: " << number << std::endl;
}

long long int	Span::longestSpan() const {
	if (elements.size() <= 1 || (elements.size() == 2 && elements[0] == elements[1]))
		throw NotEnoughElementsException();
	std::vector<int> sortedElements = elements;//Copiamos el vector para trabajar sin modificarlo
	std::sort(sortedElements.begin(), sortedElements.end());//Ordenamos los elementos de menor a mayor.
	long long int longest = std::abs(static_cast<long long int>(sortedElements.back()) - static_cast<long long int>(sortedElements.front()));//El más largo es la diferencia entre el último y el primero
	return (longest);
}

long long int	Span::shortestSpan() const {
        if (elements.size() <= 1 || (elements.size() == 2 && elements[0] == elements[1]))
            throw NotEnoughElementsException(); 
        std::vector<int> sortedElements = elements;//Copiamos el vector para trabajar sin modificarlo
		std::sort(sortedElements.begin(), sortedElements.end());//Ordenamos los elementos de menor a mayor.
		long long int shortest = std::numeric_limits<long long int>::max();//cogemos como valor inicial de shortest el valor maximo 
		for (size_t i = 0; i < sortedElements.size() - 1; ++i) {
			long long int diff = std::abs(static_cast<long long int>(sortedElements[i + 1]) - static_cast<long long int>(sortedElements[i]));
			if (diff < shortest) {//Si un rango es neor que el anterior...
				shortest = diff; //Este rango es el nuevo shortest
			}
		}
		return (shortest);
}
