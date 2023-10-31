/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:53:27 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/30 19:51:00 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp

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

