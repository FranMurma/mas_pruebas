/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:25:37 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/20 16:43:53 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class	MutantStack : public std::stack<T> {
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
//		using iterator = typename std::stack<T>::container_type::iterator; No puedo, estandar 11
		MutantStack() {
			std::cout << "[MutantStack] default constructor called." << std::endl;
		}
		~MutantStack() {
			std::cout << "[MutantStack] destructor called." << std::endl;
		}
		MutantStack(MutantStack<T> const& copy) : std::stack<T>(copy) {
			std::cout << "[MutantStack] copy constructor called." << std::endl;
		}
		MutantStack& operator=(MutantStack<T> const& copy) {
			if (this != &copy)
				std::stack<T>::operator=(copy);//llamamos al operador de asignación de la clase base std::stack<T>
			return (*this);
		}
		// Funciones para obtener iteradores de inicio y fin
		iterator begin() {
			return (this->c.begin());
		}
		iterator end() {
			return (this->c.end());
		}
};

// std::stack proporciona una interfaz de pila para almacenar elementos, pero no ofrece directamente la capacidad de iterar sobre ellos.
// using iterator = Crea un alias. Ese alias (referencia), va a ser un iterador.
// Como utilizo 'using' ese alias que es un iterador es un iterador preexistente  (que tú ya sabrás cuál es)
// Desde ahora en adelante, cuando diga "iterator", me refiero al tipo de iterador que ya está definido en la pila MutantStack
//
//typename std::stack<T>::container_type: container_type es un alias de tipo dentro de la plantilla de clase std::stack, 
//que representa el tipo de contenedor subyacente utilizado internamente para almacenar los elementos de la pila. 
//Al utilizar typename, estamos indicando que container_type es un tipo dentro de std::stack<T>.
// ::iterator: Aquí accedemos al tipo de iterador asociado al contenedor subyacente de la pila. 
// Esto nos da el tipo de iterador que se puede utilizar para recorrer los elementos dentro del contenedor.

