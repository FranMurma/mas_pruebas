/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:02:46 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 17:43:09 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

//CANONICAS
ScalarConverter::ScalarConverter() {
	std::cout << "[ScalarConverter] default constructor called." << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "[ScalarConverter] destructor called." << std::endl;
}

ScalarConverter::ScalarConverter(std::string value) : _value(value) {
	try {
		this->_type = getType();
		convert();
		std::cout << "[ScalarConverter] value constructor called." << std::endl;
		std::cout << "You have entered a " << this->_type << std::endl;
		}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

ScalarConverter::ScalarConverter(ScalarConverter const& copy) : _value(copy._value), _c(copy._c), _d(copy._d), _ld(copy._ld), _f(copy._f) {
	 std::cout << "[ScalarConverter] copy constructor called." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& copy) {
	if (this != &copy) {
		this->_value = copy._value;
		this->_c = copy._c;
		this->_d = copy._d;
		this->_ld = copy._ld;
		this->_f = copy._f;
	}
	std::cout << "[ScalarConverter] copied." << std::endl;
	return (*this);
}

//AUXILIARES

bool	ScalarConverter::isInBorders() {//chequeamos si se sale de los limites por ser nan o infinito, etc.
	if (_value.length() > 7)
		return (false);
	else if (_value == "nan" || _value == "+inf" || _value == "-inf" || _value == "inf")
		return (false);
	else if (_value == "nanf" || _value == "+inff" || _value == "-inff" || _value == "inff")
		return (false);
	return (true);
}

// BOOLEAN CHECKERS (IS_INT, CHAR, ETC.)

bool	ScalarConverter::hasDecimal() const {
	return (_ld != static_cast<int>(_ld)); // Devuelve verdadero si el valor no es igual a su versión truncada
}

bool    ScalarConverter::hasDecimalf() const {
	return (_f != static_cast<int>(_f)); // Devuelve verdadero si el valor no es igual a su versión truncada
}

bool	ScalarConverter::isChar(std::string value) {
	if (value.length() == 3 && value[0] == '\'' && isprint(value[1]) && value[2] == '\'')
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string value) {
	if (value.empty())
		return false;
	size_t	start = 0;
	if (value[start] == '+' || value[start] == '-') {
		if (value.size() < 2)
			return (false);
		start = 1;
	}
	for (size_t i = start; i < value.length(); ++i)
		if (!isdigit(value[i]))
			return (false);
	return (true);
}

bool	ScalarConverter::isDouble(std::string value) {
	size_t		decimal_point = 0;
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
			decimal_point++;
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
	}
	if (decimal_point != 1)
		return (false);
	return (true);
}

bool    ScalarConverter::isFloat(std::string value) {
	size_t		decimal_point = 0;
	if (value.empty())
		return (false);
	if (value == "nanf" || value == "+inff" || value == "-inff" || value == "inff")
		return (true);
	size_t  start = 0;
	if (value[start] == '+' || value[start] == '-') {
		if (value.size() == 1)
			return (false);
	}
	size_t i = start;
	for ( ; i < value.length() - 1; i++) {
		if (value[i] == '.')
			decimal_point++;
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
	}
	if (decimal_point != 1 || value[i] != 'f' || i != value.length() - 1)
		return (false);
	return (true);
}

//GETTERS
std::string	ScalarConverter::getType() {//Con getType() nos retorna que tipo es
	if (isChar(this->_value))
		return("c");
	else if (isInt(this->_value))
		return("d");
	else if (isDouble(this->_value) || this->_value == "nan" || this->_value == "+inf" || this->_value == "-inf" || this->_value == "inf")
		return("ld");//PASAMOS 2 VECES POR AQUI!!!!
	else if (isFloat(this->_value) || this->_value == "nanf" || this->_value == "+inff" || this->_value == "-inff" || this->_value == "inff")
		return("f");
	else 
		return ("error");
}

std::string	ScalarConverter::getValue() {
	return(this->_value);
}	

char	ScalarConverter::getChar() {
	return (this->_c);
}
 
int	ScalarConverter::getInt() {
	return (this->_d);
}

double	ScalarConverter::getDouble() {
	return (this->_ld);
}

float	ScalarConverter::getFloat() {
	return (this->_f);
}

//CONVERTERS

void	ScalarConverter::convert() {
	if (this->_type == "c")
		this->_c = _value[1];
	//Antes hemos parseado que sea entero en getType(), ahora metemos el valor en this_d
	else if (this->_type == "d")
		this->_d = static_cast<int>(atof(this->_value.c_str()));
	else if (this->_type == "ld") {
		if (this->_value == "nan" || this->_value == "+inf" || this->_value == "-inf" || this->_value == "inf")
			{
				if (this->_value == "nan")
					this->_ld = NAN;
				else if (this->_value == "+inf" || this->_value == "inf")
					this->_ld = INFINITY;
				else if (this->_value == "-inf")
					this->_ld = -INFINITY;
			}
		else
			this->_ld = static_cast<double>(atof(this->_value.c_str()));
	}
	else if (this->_type == "f") {
		if (this->_value == "nanf" || this->_value == "+inff" || this->_value == "-inff" || this->_value == "inff")
			{
				if (this->_value == "nanf")
					this->_f = NAN;
				else if (this->_value == "+inff" || this->_value == "inff")
					this->_f = INFINITY;
				else if (this->_value == "-inff")
					this->_f = -INFINITY;
			}
		else 
			this->_f = static_cast<float>(atof(this->_value.c_str()));
	}

}

void    ScalarConverter::convertToChar() {
	if (this->_type == "c") {
		return ;
	}
	else if (this->_type == "d") {
		if (this->_d >= 32 && this->_d <= 126)
			this->_c = static_cast<char>(this->_d);
		else
			throw NonDisplayableException();
	}
	else if (this->_type == "f") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
			throw ImpossibleException();
		else 
		{
			if (this->_f >= 32 && this->_f <= 126)
				this->_c = static_cast<char>(this->_f);
			else
				throw NonDisplayableException();
		}
	}
	else if (this->_type == "ld") {
		if (this->_ld == INFINITY || this->_ld == -INFINITY || this->_value == "nan")
			throw ImpossibleException();
		else {
			if (this->_ld >= 32 && this->_ld <= 126)
				this->_c = static_cast<char>(this->_ld);
			else
				throw NonDisplayableException();
		}
	}
	else if (this->_type == "error") {
		throw ImpossibleException();
	}
	if (isInBorders() == false)
		throw NonDisplayableException();
}

void    ScalarConverter::convertToInt() {
	if (this->_type == "c")
		this->_d = static_cast<int>(this->_c);
	else if (this->_type == "d")
		return ;
	else if (this->_type == "f") {
		if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
			throw ImpossibleException();
		if ((const int)this->_f >= INT_MAX || (const int)this->_f <= INT_MIN)
			throw ImpossibleException();
		this->_d = static_cast<int>(this->_f);
	}
	else if (this->_type == "ld") {
		if (this->_ld == INFINITY || this->_ld == -INFINITY || this->_value == "nan")
			throw ImpossibleException();
		this->_d = static_cast<int>(this->_ld);
	}
	else if (this->_type == "error")
		throw ImpossibleException();
}

void	ScalarConverter::convertToDouble() {
	if (this->_type == "c")
		this->_ld = static_cast<double>(this->_c);
	else if (this->_type == "d")
		this->_ld = static_cast<double>(this->_d);
	else if (this->_type == "ld")
		return ;
	else if (this->_type == "f") {
		this->_ld = static_cast<double>(this->_f);
	}
	else if (this->_type == "error")
		throw ImpossibleException();
}

void    ScalarConverter::convertToFloat() {
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
std::ostream& operator <<(std::ostream& out, ScalarConverter &obj)
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
        out << (obj.hasDecimalf()? "" : ".0");//Si no tiene decimal le anado un .0 en la salida
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
        out << (obj.hasDecimal()? "" : ".0") << std::endl;
    }
    catch(const std::exception& e)
    {
        out << "DOUBLE " << e.what() << std::endl;
    }
    return (out);
}


// EXCEPTIONS
const char  *ScalarConverter::ImpossibleException::what() const throw() {
    return ("Impossible");
}

const char  *ScalarConverter::NonDisplayableException::what() const throw() {
    return ("Non displayable");
}
