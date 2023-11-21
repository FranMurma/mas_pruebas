/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:50:39 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 20:18:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

Character::Character(std::string const &name) : _name(name), _ground(nullptr), _groundSize(0) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = nullptr;//Inicializamos el inventario a nullptr
	}
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = nullptr;
	}
	for (int i = 0; i < _groundSize; i++) {
		delete _ground[i];
		_ground[i] = nullptr;
	}
	delete[] _ground; // Liberamos la memoria asignada a _ground
	_ground = nullptr; // Establecemos _ground a nullptr para evitar problemas de acceso accidental
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_groundSize = other._groundSize;
		for (int i = 0; i < 4; ++i) {//Primero liberamos la memoria del inventario y suelo
			delete _inventory[i];
		}
		for (int i = 0; i < _groundSize; i++) {
			delete _ground[i];
		}
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i])
				//copia profunda de cada elemento del inventario y suelo
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
		for (int i = 0; i < _groundSize; i++) {
			if (other._ground[i])
				_ground[i] = other._ground[i]->clone();
			else
				_ground[i] = nullptr;
		}
		_name = other._name;
	}
	return *this;
}

Character::Character(const Character &other) : _ground(nullptr), _groundSize(0) {
	if (this != &other)
		*this = other;
}

std::string const &Character::getName() const {
	return (_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == nullptr) {
			_inventory[i] = m;//El primer slot libre sera llenado con m y saldra
			return;
		}
	}
	std::cout << "[Character] Inventory is full. Cannot equip more materia." << std::endl;
	//Si llega aqui es que no ha encontrado un slot libre.
}

void	Character:: unequip(int idx) {//Funcion para desequipar una materia en la posicion idx
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr) {
		std::cout <<"[Character] unequiped materia " << _inventory[idx]->getType() << std::endl;
		// Aumentar el tamaño del array de suelo (_ground)
		AMateria** newGround = new AMateria*[_groundSize + 1];
		for (int i = 0; i < _groundSize; ++i) {
			newGround[i] = _ground[i];//Copiamos todo lo del viejo _ground en el nuevo
		}
		newGround[_groundSize] = _inventory[idx];//Copiamos en el ultimo espacio la materia
		_groundSize++;//el temano de groundSize crece en 1
		delete[] _ground;
		_ground = newGround;
		_inventory[idx] = nullptr;//Vaciamos esa posicion del inventario
	}
	else
		std::cout << "[Character] Invalid index or empty slot. Cannot unequip materia." << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr) {
		_inventory[idx]->use(target);
		std::cout << "[Character] Used materia " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
	}
	else
		std::cout << "[Character] Invalid index or empty slot. Cannot use materia." << std::endl;
}
