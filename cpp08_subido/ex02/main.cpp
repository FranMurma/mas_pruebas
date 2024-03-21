/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:48:43 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/20 20:13:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	MutantStack<int> mstack;
	std::cout << "Creating a MutanStack, called mstack\nWe are adding 2 elements in the top of the pile: 5 and 17\n";
	mstack.push(5);//Anadimos elementos en la parte superior de la pila
	mstack.push(17);
	std::cout << "Printing the last element added (it should print '17'): " << std::endl;
	std::cout << mstack.top() << std::endl;//Imprime el elemento mas reciente (17)
	std::cout << "Now, we are going to delete the last element (17)" << std::endl;
	mstack.pop();//Elimina elemento mas reciente de la pila (17)
	std::cout << "So when we print the size of the pile, it should show us '1' (that is, the number 5):" << std::endl;
	std::cout << mstack.size() << std::endl;// Imprime el tamano de la pila (1)
	std::cout << "We are adding to the pile: 3, 5, 737, and 0" << std::endl;
	mstack.push(3);// Anadimos mas elementos (3, 5, 737, ..., 0)
	mstack.push(5);
	mstack.push(737); 
	//[...] 
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();//Se declara un iterador it, se inicializa con el iterador de inicio de la pila mstack usando el método begin.
	MutantStack<int>::iterator ite = mstack.end();//Se declara iterador ite inicializado al final de la pila
	++it;//Se incrementa el iterador it para que apunte al siguiente elemento de la pila mstack.
	--it;//Se decrementa, vuelve al punto inicial.
	std::cout << "Printing the elements of the stack MutantStack iterating. If all is okay, we well see: 5, 3, 5, 737, 0." << std::endl; 
	while (it != ite) {//Iteramos ite y vamos imprimiendo los valores de mstack hasta llegar al final
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);//Creamos una pila s que es copia de mstack usando el constructor de copia de std::stack<int>.
//	MutantStack<int> mstack2 = mstack; // Esto debería llamar al constructor de copia	
	return (0);
}
