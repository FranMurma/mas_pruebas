/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:12:33 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 17:35:11 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main( void )
{
    {
		std::cout << "Generating a random *Base object\n";
        Base *basePtr;

        basePtr = generate();
        identify(basePtr);
    }
    {
		std::cout << "Creating an A object\n";
        A base;

		std::cout << "Identifying the object\n";
        identify(base);
    }
}
