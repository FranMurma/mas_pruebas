/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:58:18 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 17:38:57 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <random>
#include "Base.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base::~Base() {
	std::cout << "[Base] destructor called." << std::endl;
}

int	random(int low, int high) {
	std::random_device rd;//generador de números aleatorios que produce números aleatorios no deterministas.
	std::mt19937 gen(rd());//proporciona una semilla al generador de números pseudoaleatorios std::mt19937.

	std::uniform_int_distribution<> dist(low, high);//retorna enteros de forma uniforme en el rango
	return dist(gen);
}

Base*	generate() {
	switch (int num = random(0, 2)) {
		case 0:
			std::cout << "Randomly creating object of type A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Randomly creating object of type B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Randomly creating object of type C" << std::endl;
			return (new C());
	}
	return (nullptr);
}

// Function to identify the type using a pointer
void identify(Base* p) {
	std::cout << "\nTrying to find out what kind ob object is through its pointer:\n";
	A* pa = (dynamic_cast<A*>(p));
	if (pa)
		std::cout << "Object type identified as: A\n" << std::endl;
	B* pb = (dynamic_cast<B*>(p));
	if (pb)
		std::cout << "Object type identified as: B\n" << std::endl;
	C* pc = (dynamic_cast<C*>(p));
	if (pc)
		std::cout << "Object type identified as: C\n" << std::endl;
}

//Function to identify the type using a reference
void identify(Base& p) {
	std::cout << "\nTrying to find out what kind ob object is through its address:\n";
	if (dynamic_cast<A*>(&p)) {
		std::cout << "Object type identified as: A" << std::endl;
		}
	else if (dynamic_cast<B*>(&p)) {
		std::cout << "Object type identified as: B" << std::endl;
		}
	else if (dynamic_cast<C*>(&p)) {
		std::cout << "Object type identified as: C" << std::endl;
	}
	else
		std::cout << "Cast error!!!" << std::endl;
}
