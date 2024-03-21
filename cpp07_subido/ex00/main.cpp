/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:45:41 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 19:24:38 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void )
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << std::endl << std::endl << std::endl;
        int a = 2;
        int b = 3;
		std::cout << "Swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
		std::cout << std::endl << "Min" << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << std::endl << "Max" << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::cout << std::endl;
		std::cout << std::endl << "Swap between strings:" << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
		std::cout << "c = " << c << ", d = " << d << std::endl;
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << std::endl << "Min and max strings:" << std::endl;
        std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
        std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    }
    std::cout << std::endl;
    {
        int a = 2;
        int b = 3;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "Two swaps" << std::endl;
		std::cout << "First:" << std::endl;
        ::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap(a, b);
		std::cout << "Second:" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Two equals" << std::endl;
        int a = 2;
        int b = 3;
        int c = 3;
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << std::endl << "Swap between a and c:" << std::endl;
        ::swap(a, c);
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << std::endl << "Min in a and c:" << std::endl;
        std::cout << "min(a, c) = " << ::min(a, c) << std::endl;
		std::cout << std::endl << "Max in a and c:" << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    }
/*	std::cout << std::endl;
	{
		std::cout << "\nLet's see 2 differente types:" << std::endl;
		int		a = 2;
		double	b = 4.2;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = ";
		std::cout << ::min(static_cast<double>(a), b) << std::endl;

	}*/
    return (0);
}
