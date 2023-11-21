/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:33:10 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 20:15:15 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_learnedMaterias[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		delete _learnedMaterias[i];
	}

}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; ++i) {
		if (other._learnedMaterias[i]) {
			_learnedMaterias[i] = other._learnedMaterias[i]->clone();
		} else {
			_learnedMaterias[i] = nullptr;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete _learnedMaterias[i];
			if (other._learnedMaterias[i]) {
				_learnedMaterias[i] = other._learnedMaterias[i]->clone();
			}
			else {
				_learnedMaterias[i] = nullptr;
			}
		}
	}
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	// Buscar un espacio libre para aprender la materia
	int i;
	for (i = 0; i < 4; ++i) {
		if (_learnedMaterias[i] == nullptr) {
			break;
		}
	}
	if (i < 4) {
		_learnedMaterias[i] = materia->clone();
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
		_learnedMaterias[3] = materia->clone();
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
