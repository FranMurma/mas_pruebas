/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:02:46 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/07 19:24:05 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Conversor.hpp"

#include <cmath>
#include <limits>
#include <string>
#include <iostream>

//CANONICAS
Conversor::Conversor() {
	std::cout << "[Conversor] default constructor called." << std::endl;
}

Conversor::~Conversor() {
	std::cout << "[Conversor] destructor called." << std::endl;
}

Conversor::Conversor(std::string value) : _value(value) {
	try {
		this->_type = getType();
		convert();
		std::cout << "[Conversor] value constructor called." << std::endl;
		std::cout << "You have entered a " << this->_type << std::endl;
		}
	catch(const std::exception &e) {
		this->_type = "error";
		std::cerr << e.what() << std::endl;
	}
}

Conversor::Conversor(Conversor const& copy) : _value(copy._value), _c(copy._c), _d(copy._d), _ld(copy._ld), _f(copy._f) {
	 std::cout << "[Conversor] copy constructor called." << std::endl;
}

Conversor& Conversor::operator=(Conversor const& copy) {
	if (this != &copy) {
		this->_value = copy._value;
		this->_c = copy._c;
		this->_d = copy._d;
		this->_ld = copy._ld;
		this->_f = copy._f;
	}
	std::cout << "[Conversor] copied." << std::endl;
	return (*this);
}

//AUXILIARES
bool	Conversor::isPrintable(char c) {
	return (c >= 32 && c <= 126);
}

bool	Conversor::isInBorders() {//chequeamos si se sale de los limites por ser nan o infinito, etc.
	if (_value.length() > 7)
		return (false);
	else if (_value == "nan" || _value == "+inf" || _value == "-inf" || _value == "inf") {
		if (_value == "nan")
			this->_ld = NAN;
		else if (_value == "+inf")
			this->_ld = INFINITY;
		else if (_value == "-inf")
			this->_ld = -INFINITY;
		return (false);
	}
	else if (_value == "nanf" || _value == "+inff" || _value == "-inff" || _value == "inff") {
		if (_value == "nanf")
			this->_f = NAN;
		else if (_value == "+inff")
			this->_f = INFINITY;
		else if (_value == "-inff")
			this->_f = -INFINITY;
		return (false);
	}
	return (true);
}

// BOOLEAN CHECKERS (IS_INT, CHAR, ETC.)
bool	Conversor::isChar(std::string value) {
	if (value.length() == 3 && value[0] == '\'' && isPrintable(value[1]) && value[2] == '\'') {
//		std::cout << value.length() << std::endl << value[0] << std::endl << value[1] << std::endl << value[2] << std::endl;
//		std::cout << "IS CHAR\n";
		return (true);
	}
//	std::cout << value.length() << std::endl << value[0] << std::endl << value[1] << std::endl << value[2] << std::endl;
//	std::cout << "IS not a CHAR\n";
	return (false);
}

bool	Conversor::isInt(std::string value) {
	long long	result = 0;
	int			negative = 1;
	if (value.empty())
		return false;
	size_t	start = 0;
	if (value[start] == '+' || value[start] == '-') {
		if (value.size() == 1)
			return (false);
		if (value[0] == '-')
			negative = -1;
		start = 1;
	}
	for (size_t i = start; i < value.length(); ++i) {
		if (!isdigit(value[i]))
			return (false);
		result = result * 10 + (value[i] - '0');//Convertimos el string a decimales
	}
	if ((negative == -1 && -result < INT_MIN) || (negative == 1 && result > INT_MAX))
		return (false);
	result = result * negative;
	this->_d = result;
	return (true);
}

bool	Conversor::isDouble(std::string value) {
	size_t		point = 0;
	int			negative = 1;
	long double	result = 0;
	size_t		start = 0;

	if (value.empty())
		return (false);
	if (value == "nan" || value == "+inf" || value == "-inf" || value == "inf")
		return (true);
	if (value[start] == '+' || value[start] == '-') {
		if (value.size() == 1)
			return (false);
		start = 1;
	}
	for (size_t i = start; i < value.length(); ++i) {
		if (value[i] == '.')
			point++;
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
		if (isdigit(value[i]))
			result = result * 10 + (value[i] - '0');
	}
	if (point != 1)
		return (false);
	if ((negative == -1 && -result < LONG_MIN) || (negative == 1 && result > LONG_MAX))
		return (false);
	return (true);
}

bool    Conversor::isFloat(std::string value) {
	size_t		point = 0;
	long double	result = 0;
	if (value.empty())
		return (false);
	size_t  start = 0;
	if (value[start] == '+' || value[start] == '-') {
		if (value.size() == 1)
			return (false);
		start = 1;
	}
	size_t i = start;
	for ( ; i < value.length() - 1; ++i) {
		if (value[i] == '.')
			point++;
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
		if (isdigit(value[i]))
			result = result * 10 + (value[i] - '0');
	}	if (point != 1 || value[i] != 'f' || i != value.length() - 1)
		return (false);
	return (true);
}

//GETTERS
std::string	Conversor::getType() {//Con getType() nos retorna que tipo es
	if (isChar(this->_value))
		return("c");
	else if (isInt(this->_value))
		return("d");
	else if (isDouble(this->_value) || this->_value == "nan" || this->_value == "+inf" || this->_value == "-inf" || this->_value == "inf")
		return("ld");
	else if (isFloat(this->_value) || this->_value == "nanf" || this->_value == "+inff" || this->_value == "-inff" || this->_value == "inff")
		return("f");
//	printf("AQUI FALLA!!!\n");
	throw ImpossibleException();
}

std::string	Conversor::getValue() {
	return(this->_value);
}	

char	Conversor::getChar() {
	return (this->_c);
}
 
int	Conversor::getInt() {
	return (this->_d);
}

double	Conversor::getDouble() {
	return (this->_ld);
}

float	Conversor::getFloat() {
	return (this->_f);
}

//CONVERTERS

void	Conversor::convert() {
	int			start = 0;
	int			sign = 1;
	size_t		point = 0;
	long double result = 1.0L;
	size_t		decimal_point = 0;

	if (this->_type == "c")
		this->_c = _value[1];
	else if (this->_type == "d") {
		if (_value[0] == '+' || _value[start] == '-')
			start = 1;
		if (_value[0] == '-')
			sign = -1;
		for (size_t i = start; i < _value.length() ; ++i) {
			result = result * 10 + (_value[i] - '0');//Convertimos el string a decimales
			}
		if ((sign == -1 && -result < INT_MIN) || (sign == 1 && result > INT_MAX))
			throw ImpossibleException();
		result = result * sign;
		this->_d = result;
	}
	else if (this->_type == "ld") {
		if (this->isInBorders() == false) {
			if (this->_ld == INFINITY || this->_ld == -INFINITY || this->_ld == NAN)
				throw ImpossibleException();
		}
		if (_value[0] == '+' || _value[start] == '-')
			start = 1;
		if (_value[0] == '-')
			sign = -1;
		for (size_t i = start; i < _value.length(); ++i) {
				result = result * 10 + (_value[i] - '0');
				if (point == 1)
					decimal_point++;
				if (_value[i] == '.')
					point++;
		}
		result = (result / std::pow(10.0L, decimal_point)) * sign; // Utilizar std::pow para mantener la precisión
		this->_ld = result;
	}
	else if (this->_type == "f") {
		if (this->isInBorders() == false) {
			if (this->_f == INFINITY || this->_f == -INFINITY || this->_f == NAN)
				throw ImpossibleException();
		}
		if (_value[0] == '+' || _value[start] == '-')
			start = 1;
		if (_value[0] == '-')
			sign = -1;
		for (size_t i = start; i < _value.length(); ++i) {
			result = result * 10 + (_value[i] - '0');
			if (point == 1)
				decimal_point++;
			if (_value[i] == '.')
				point++;
		}
		result = (result / std::pow(10.0f, decimal_point)) * sign; // Utilizar std::pow para mantener la precisión
		this->_f = result;
	}
	else
		throw ImpossibleException();
}
////
///
// Hay que pasar los valores a infinity -infinity y nan en el conversor.
// convert() {
// }
//
//
//
//
//
void    Conversor::convertToChar() {
	if (this->_type == "c") {
		return ;
	}
	else if (this->_type == "d")
		this->_c = static_cast<char>(this->_d);
	else if (this->_type == "f") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
			throw ImpossibleException();
		this->_c = static_cast<char>(this->_f);
	}
	else if (this->_type == "ld") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nan")
			throw ImpossibleException();
		this->_c = static_cast<char>(this->_ld);
	}
	else if (this->_type == "error") {
		throw ImpossibleException();
	}
	if (!isprint(this->_c))
		throw NonDisplayableException();
}

void    Conversor::convertToInt() {
	if (this->_type == "c")
		this->_d = static_cast<int>(this->_c);
	else if (this->_type == "d")
		return ;
	else if (this->_type == "f") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
			throw ImpossibleException();
		if ((const int)this->_c >= INT_MAX || (const int)this->_c <= INT_MIN)
			throw ImpossibleException();
		this->_d = static_cast<int>(this->_f);
	}
	else if (this->_type == "ld") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nan")
			throw ImpossibleException();
		this->_d = static_cast<int>(this->_ld);
	}
	else if (this->_type == "error")
		throw ImpossibleException();
}

void	Conversor::convertToDouble() {
	if (this->_type == "c")
		this->_ld = static_cast<double>(this->_c);
	else if (this->_type == "d")
		this->_ld = static_cast<double>(this->_d);
	else if (this->_type == "ld")
		return ;
	else if (this->_type == "f") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
			throw ImpossibleException();
		this->_ld = static_cast<double>(this->_f);
	}
	else if (this->_type == "error")
		throw ImpossibleException();
}

void    Conversor::convertToFloat() {
    if (this->_type == "c") // char
        this->_f = static_cast<float>(this->_c);
    else if (this->_type == "d") // int
        this->_f = static_cast<float>(this->_d);
    else if (this->_type == "f") // float
        return ;
    else if (this->_type == "ld") // double
        this->_f = static_cast<float>(this->_ld);
    else if (this->_type == "error")
        throw ImpossibleException();
}

//Sobrecarga para imprimir
std::ostream& operator <<(std::ostream& out, Conversor &obj)
{
    if (obj.getType() == "error")
        return (out << "Incorrect format");
    out << obj.getValue() << " is... \n";
    try
    {
        obj.convertToChar();
        out << "CHAR:  '" << obj.getChar() << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        out << "CHAR:  " << e.what() << std::endl;
    }
    try
    {
        obj.convertToInt();
        out << "INT:   " << obj.getInt() << std::endl;
    }
    catch(const std::exception& e)
    {
        out << "INT:   " << e.what() << std::endl;
    }
    try
    {
        obj.convertToFloat();
        out << "FLOAT: " << obj.getFloat();
        out << (obj.isInBorders()? ".0" : "");
        out << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        out << "FLOAT: " << e.what() << std::endl;
    }
    try
    {
        obj.convertToDouble();
        out << "DOUBLE: " << obj.getDouble();
        out << (obj.isInBorders()? ".0" : "") << std::endl;
    }
    catch(const std::exception& e)
    {
        out << "DOUBLE " << e.what() << std::endl;
    }
    return (out);
}


// EXCEPTIONS
const char  *Conversor::ImpossibleException::what() const throw() {
    return ("Impossible");
}

const char  *Conversor::NonDisplayableException::what() const throw() {
    return ("Non displayable");
}
