/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:10:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/20 15:00:28 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int main()
{
	std::cout << std::endl;
	std::cout << GREEN << "Creation of array of 4 animals" << RESET << std::endl;
	std::cout << std::endl;
    Animal *animals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
			std::cout << GREEN << "Creation of a concret dog:" << RESET << std::endl;
            animals[i] = new Dog();
			std::cout << GREEN << "Sound function:" << RESET << std::endl;
            animals[i]->makeSound(); //will output the cat sound!
			std::cout << std::endl;
        }
        else
        {
			std::cout << GREEN << "Creation of a concret cat:" << RESET << std::endl;
            animals[i] = new Cat();
			std::cout << GREEN << "Sound function:" << RESET << std::endl;
            animals[i]->makeSound();
			std::cout << std::endl;
        }
    }
    for (int i = 0; i < 4; i++) {
		std::cout << GREEN << "Deleting animals:" << RESET << std::endl;
        delete animals[i];
		std::cout << std::endl;
	}

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak 
	delete i;
//	Animal myAnimal;
    return (0);
}
