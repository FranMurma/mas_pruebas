/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:58:59 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/22 19:15:52 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iomanip> // Para utilizar std::set

// Colores ANSI para la salida en la consola
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

/*int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice"); 
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0; }*/
/*
int main()
{
    {
    IMateriaSource* src = new MateriaSource(); // Default MateriaSource constructor called
    src->learnMateria(new Ice()); // Default ice from AMateria constructor called & Default Ice constructor called
    src->learnMateria(new Cure()); // Default cure from AMateria constructor called & Default Cure constructor called
    ICharacter* me = new Character("me"); // Default character me created
    AMateria* tmp;
    tmp = src->createMateria("ice"); // Default ice from AMateria constructor called & Copy constructor Ice ice called
    me->equip(tmp); // Character me is equiped with ice
    tmp = src->createMateria("cure"); // Default cure from AMateria constructor called & Copy constructor cure from Cure called
    me->equip(tmp); // Character me is equiped with cure
    ICharacter* bob = new Character("bob"); // Default character bob created
    me->use(0, *bob); // Ice ice used on bob
    me->use(1, *bob); // Cure cure used on bob
    delete bob;
    delete me;
    delete src;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    {
    ICharacter* me = new Character("player_1");
    me->unequip(1);
    delete me;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    {
    ICharacter* me = new Character("player_1");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(0);
    me->unequip(1);
    delete src;
    delete me;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Asignación (igualación)
    // Crear dos personas. Equipar a una. Igualarlas. Cerrar.
    {
    IMateriaSource* src = new MateriaSource();
    ICharacter* p1 = new Character("Player_1");
    ICharacter* p2 = new Character("Player_2");
    AMateria* tmp;

    src->learnMateria(new Ice()); // Aprendemos la materia "ice"
    tmp = src->createMateria("ice"); // Creamos la materia "ice"
    p1->equip(tmp); // Equipamos el player_1
    *p2 = *p1; // Igualamos el player_2 al player_1 // ESTO NO
    // p2 = p1; // Igualamos la dirección de memoria el player_2 al player_1
    // ESTO NO SE PUEDE HACER PORQUE ESTAMOS SOBREESCRIBIENDO P1, RETRASO
    // p2 queda en el limbo, la direccion de memoria se reemplaza
    p1->use(0, *p2); // Ice ice used on bob
    p2->use(0, *p1); // Ice ice used on bob
    delete src; // OJO QUE AQUÍ SE NOS QUEDABA UN LEAK
    delete p1;
    delete p2;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Constructor copia
    {
    IMateriaSource* src = new MateriaSource();
    Character *p1 = new Character("Player_1");
    Character *p2 = new Character(*p1);
    // *p2(dynamic_cast<ICharacter&>(*p1));
    AMateria* tmp;

    src->learnMateria(new Ice());
    tmp = src->createMateria("ice");
    // si equipamos p1, no hace falta hacer un delete porque p1 borra sus materias
    // en caso contrario, como tmp no se usa, hay que hacer un delete
    // p1->equip(tmp); // Ice ice used on bob
    p1->use(0, *p2); // Ice ice used on bob
    p2->use(0, *p1); // Ice ice used on bob
    delete p1;
    delete p2;
    delete src;
    delete tmp;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Utilizar p1 sin haber creado una materia
    {
    ICharacter  *p1 = new Character("Player_1");
    ICharacter  *p2 = new Character("Player_2");

    p1->use(0, *p2); // Ice ice used on bob
    delete p1;
    delete p2;
    }
    return (0);
}*/

int main() {
    std::cout << "Creando MateriaSource..." << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << "Aprendiendo Ice..." << std::endl;
    src->learnMateria(new Ice());

    std::cout << "Creando Character 'me'..." << std::endl;
    ICharacter* me = new Character("me");

    std::cout << "Creando Ice y Cure..." << std::endl;
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    std::cout << "Equipando Ice y Cure a 'me'..." << std::endl;
    me->equip(ice);
    me->equip(cure);

    std::cout << "Creando Character 'bob'..." << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "Usando materias contra 'bob'..." << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    // Verificamos que las materias no se hayan destruido y que 'me' no tenga fugas de memoria.

    std::cout << "Dejando Ice en el suelo..." << std::endl;
    me->unequip(0);

    std::cout << "Eliminando objetos..." << std::endl;
    delete bob;
    delete me;
    delete src;

//    std::cout << GREEN << "Prueba completada sin fugas de memoria." << RESET << std::endl;

    return 0;
}
