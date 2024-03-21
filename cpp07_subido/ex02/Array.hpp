/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:37:16 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/16 19:41:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept> // Para usar std::out_of_range

template<typename T>
class Array {
	private :
		T *elements; // Puntero al inicio del array dinámico
		size_t length; // Longitud del array

	public :
		Array() : elements(nullptr), length(0) {
			std::cout << "[Array] void constructor called\n";
		}

		explicit Array(size_t n) : length(n) {
			std::cout << "[Array] with length (" << this->length << ") constructor called\n";
			elements = new T[n](); // Se inicializan todos los elementos por defecto
		}

		Array(Array const& copy) {
			if (this != &copy) {
				std::cout << "[Array] copy constructor called\n";
				this->length = copy.length;
				this->elements = new T[length];
				for (size_t i = 0; i < length; i++)
					this->elements[i] = copy.elements[i];
			}
		}

		~Array() {
			std::cout << "[Array] destructor called\n";
			delete[] elements;
		}

		Array& operator=(Array const& copy) {
			if (this != &copy) {
				delete[] this->elements; // Liberar la memoria previamente asignada
				this->length = copy.length;
				this->elements = new T[length];
				for (size_t i = 0; i < length; i++)
					this->elements[i] = copy.elements[i];
			}
			return(*this);
		}

		T& operator[](size_t index) {
			if (index >= this->length)
				throw std::out_of_range("Index out of range");
			return(elements[index]);
		}

		size_t	size() const {
			return(this->length);
		}

		bool empty() const {//Comprobacion por si el array es vacio
			return(length == 0);
		}
};
# endif
