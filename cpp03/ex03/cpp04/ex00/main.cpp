/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:14:40 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 18:50:45 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "Dog.hpp"
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int	main() 
{
	{
		std::cout << std::endl;
		std::cout << GREEN << "CORRECT ANIMALS:" << std::endl;
		std::cout << std::endl;
		std::cout << "Create an undifferentiated animal:" << RESET <<std::endl;
		const Animal* animal = new Animal();
		std::cout << GREEN << "Sound function:" << RESET << std::endl;
		animal->makeSound();
		std::cout << GREEN << "Delete:"<< RESET << std::endl;
		delete animal;
		std::cout << std::endl;
		
		std::cout << GREEN << "Create a dog::"<< RESET << std::endl;
		const Animal* dog = new Dog();
		std::cout << GREEN<< "Sound function:"<< RESET << std::endl;
		dog->makeSound(); //will output the dog sound!
		std::cout << GREEN << "Delete:"<< RESET << std::endl;
		delete dog;
		std::cout << std::endl;
		
		std::cout << GREEN << "Create a cat:"<< RESET << std::endl;
		const Animal* cat = new Cat();
		std::cout << GREEN << "Sound function:"<< RESET << std::endl;
		cat->makeSound();//will output the dog sound!
		std::cout << GREEN << "Delete:"<< RESET << std::endl;
		delete cat;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
    {
		std::cout << GREEN << "NON CORRECT ANIMALS:" << std::endl;
		std::cout << std::endl;
		std::cout << "Create a wrong undifferenciated animal:" << RESET <<std::endl;
		const WrongAnimal* animal = new WrongAnimal();
		std::cout << GREEN << "Sound function: " << RESET << std::endl;;
		animal->makeSound();
		std::cout << GREEN << "Delete:"<< RESET << std::endl;
		delete animal;
		std::cout << std::endl;

		std::cout << GREEN << "Create a wrong cat:" << RESET <<std::endl;
		const WrongAnimal* snake = new WrongCat();
		std::cout << GREEN << "Type of wrong animal: " << RESET << snake->getType() << std::endl;
		std::cout << GREEN << "Sound function:" << RESET << std::endl;
		snake->makeSound();
		std::cout << GREEN << "Delete:"<< RESET << std::endl;
		delete snake;
    }
    return (0);
}
