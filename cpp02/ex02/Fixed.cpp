/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:09:53 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/30 18:15:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed_point = intValue << _nFractBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixed_point = roundf(floatValue * (1 << _nFractBits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}

float Fixed::toFloat() const
{
    return (float)this->_fixed_point / (1 << _nFractBits);
}

int Fixed::toInt() const
{
    return this->_fixed_point >> _nFractBits;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_fixed_point = other.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

// Comparación
bool Fixed::operator>(const Fixed& other) const
{
    return this->_fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->_fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->_fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->_fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->_fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->_fixed_point != other._fixed_point;
}

// Operadores aritméticos
Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

// Operadores de incremento y decremento
Fixed& Fixed::operator++()
{
    this->_fixed_point += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->_fixed_point -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

// Funciones estáticas
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

