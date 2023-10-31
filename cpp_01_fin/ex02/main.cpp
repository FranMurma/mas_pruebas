/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:46:57 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/23 16:39:04 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string myString = "HI THIS IS BRAIN";
	std::string* stringPTR;
	stringPTR = &myString;
	std::string& stringREF = myString;

	std::cout <<"The memory address of the string variable is: " <<&myString <<"\n";
	std::cout <<"The memory address held by stringPTR is: " <<stringPTR <<"\n";
	std::cout <<"The memory address held by stringREF is: " <<&stringREF <<std::endl;

	std::cout <<"The value of the string variable: " <<myString <<std::endl;
	std::cout <<"The value pointed to by stringPTR: " <<*stringPTR <<std::endl;
	std::cout <<"The value pointed to by stringREF: " <<stringREF <<std::endl;
	return (0);
}
