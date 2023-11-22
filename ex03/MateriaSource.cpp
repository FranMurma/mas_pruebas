/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:33:10 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/22 19:15:34 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_learnedMaterias[i] = nullptr;
	}
	std::cout << "[MateriaSource] default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (this->_learnedMaterias[i])
			delete _learnedMaterias[i];
	}
	std::cout << "[MateriaSource] default destructor called" << std::endl;

}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; ++i) {
		if (other._learnedMaterias[i]) {
			_learnedMaterias[i] = other._learnedMaterias[i];
		} else {
			_learnedMaterias[i] = nullptr;
		}
	}
	std::cout << "[MateriaSource] copied" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete _learnedMaterias[i];
			if (other._learnedMaterias[i]) {
				_learnedMaterias[i] = other._learnedMaterias[i];
			}
			else {
				_learnedMaterias[i] = nullptr;
			}
		}
	}
    return *this;
}

/*
void MateriaSource::learnMateria(AMateria* materia) {
	// Buscar un espacio libre para aprender la materia
	int i;
	for (i = 0; i < 4; ++i) {
		if (_learnedMaterias[i] == nullptr) {
			break;
		}
	}
	if (i < 4) {
		_learnedMaterias[i] = materia;
		std::cout << "Learned materia of type: " << materia->getType() << std::endl;
		}
	else {
		std::cout << "You have not enough memory to learn another materia. You will forgot yor first materia" << std::endl;
		delete _learnedMaterias[0];//Borramos la primera materia
		_learnedMaterias[0] = nullptr; // Establecer el puntero a nullptr
		for (int i = 0; i < 3; ++i) {
			delete _learnedMaterias[i];
			_learnedMaterias[i] = _learnedMaterias[i + 1];
		}
		_learnedMaterias[3] = nullptr;
		_learnedMaterias[3] = materia;
		std::cout << "Forgot first materia and learned new materia of type: " << materia->getType() << std::endl;
		delete materia;
	}
}*/

void MateriaSource::learnMateria(AMateria* materia) {
    int emptySlot = -1;

    // Buscar un espacio libre para aprender la materia
    for (int i = 0; i < 4; ++i) {
        if (_learnedMaterias[i] == nullptr) {
            emptySlot = i;
            break;
        }
    }

    if (emptySlot != -1) {
        // Hay un espacio libre para aprender la nueva materia
        _learnedMaterias[emptySlot] = materia;
        std::cout << "Learned materia of type: " << materia->getType() << std::endl;
    } else {
        // No hay espacio libre, olvidar la primera materia
        delete _learnedMaterias[0];
        _learnedMaterias[0] = nullptr;

        // Desplazar las materias restantes
        for (int i = 0; i < 3; ++i) {
            _learnedMaterias[i] = _learnedMaterias[i + 1];
        }

        // Aprender la nueva materia en el último espacio
        _learnedMaterias[3] = materia;
        std::cout << "Forgot first materia and learned new materia of type: " << materia->getType() << std::endl;
    }
}


AMateria* MateriaSource::createMateria(const std::string& type) {
    // Buscar la materia aprendida con el tipo especificado
    for (int i = 0; i < 4; ++i) {
		if (_learnedMaterias[i]) {
			printf("Materia aprendida en el slot numero [%i], es: [%s]\n", i, _learnedMaterias[i]->getType().c_str());
			if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type) {
				// Clonar la materia y devolverla
				std::cout << "Created materia of type: " << type << std::endl;
				return _learnedMaterias[i]->clone();
			}
        }
    }
    // Si no se encuentra una materia aprendida con el tipo especificado, devolver nullptr
	std::cout << "Materia of type " << type << " not found in learned materias." << std::endl;
	return nullptr;
}
