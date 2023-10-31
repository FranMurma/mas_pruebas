/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:53:12 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/30 17:43:11 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // Para la función roundf

class Fixed
{
private:
    int _fixed_point;
    static const int _nFractBits = 8;

public:
    Fixed(); // Constructor por defecto
    Fixed(const int intValue); // Constructor con entero
    Fixed(const float floatValue); // Constructor con flotante
    Fixed(const Fixed& other); // Constructor de copia
    ~Fixed(); // Destructor

    int getRawBits() const; // Obtener los bits brutos
    void setRawBits(int const raw); // Establecer los bits brutos
    
    float toFloat() const; // Convertir a punto flotante
    int toInt() const; // Convertir a entero
    
    Fixed& operator=(const Fixed& other); // Sobrecarga del operador de asignación
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); // Sobrecarga del operador de inserción en un flujo de salida

#endif

