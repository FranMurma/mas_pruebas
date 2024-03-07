#include "Conversor.hpp"

#include <cmath>
#include <limits>
#include <string>
#include <iostream>

// static_cast

/*
   CONSTRUCTORES / DESTRUCTORES
*/
Conversor::Conversor( void )
{
    std::cout << "Default conversor constructor created" << std::endl;
}

Conversor::Conversor(std::string value) : _value(value)
{
    try
    {
        this->_type = getType();
        convert();
        std::cout << "Conversor constructor with value created" << std::endl;
    }
    catch(const std::exception& e)
    {
        this->_type = "error";
        std::cerr << e.what() << '\n';
    }
}

Conversor::Conversor(const Conversor &copy) : _value(copy._value), _c(copy._c), _d(copy._d), _ld(copy._ld), _f(copy._f)
{
    std::cout << "Default conversor copy created" << std::endl;
}

Conversor &Conversor::operator=(Conversor const &copy)
{
    if (&copy == this)
        return (*this);
    _value = copy._value;
    _c = copy._c;
    _d = copy._d;
    _ld = copy._ld;
    _f = copy._f;
    std::cout << "Default conversor operator = created" << std::endl;
    return (*this);
}

Conversor::~Conversor( void )
{
    std::cout << "Default conversor destructor created" << std::endl;
}

/**
 * @brief Printamos la conversión en función del tipo que sea
 * Divide un valor de punto flotante en partes fraccionarias y enteras
 * 
 * @param out 
 * @param obj 
 * @return std::ostream& 
 */
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
        out << (obj.isSpecial()? ".0" : "");
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
        out << (obj.isSpecial()? ".0" : "") << std::endl;
    }
    catch(const std::exception& e)
    {
        out << "DOUBLE " << e.what() << std::endl;
    }
    return (out);
}


/*
   AUX
*/
/**
 * @brief Miramos si es printable.
 * No son printables los floats o doubles nan, inf, inff ni los que tienen mas de 8 digitos
 * 
 * @return true 
 * @return false 
 */
bool Conversor::isSpecial( void )
{
    if (_value == "nan" || _value == "+inf" || _value == "-inf" || _value == "inf")
		return (false);
	if (_value == "nanf" || _value == "+inff" || _value == "-inff" || _value == "inff")
		return (false);
    if (this->_value.length() >= 8)
        return (false);
    return (true);
}

bool Conversor::isPrintable(char c)
{
    return (c >= 32 && c <= 126);
}

int Conversor::nbrOcurrences(std::string value, char c)
{
    int count = 0;

    for (int i = 0; value[i]; i++)
    {
        if (value[i] == c)
            count++;
    }
    return (count);
}


/*
   BOOLEANOS DE QUÉ TIPO ES
*/
bool Conversor::isChar(std::string value)
{
    if (value.length() == 3 && value[0] == '\'' && isPrintable(value[1]) && value[2] == '\'')
        return (true);
    return (false);
}

/**
 * @brief Check it the value is an int
 * find_first_not_of devuelve la posición en la que ha encontrado una ocurrencia diferente
 * 
 * @param value 
 * @return true 
 * @return false
 */
bool Conversor::isInt(std::string value)
{
    int start = 0;

    if (nbrOcurrences(value, '-') > 1)
        return (false);
    if (value[0] == '-')
		start++;
    if (value.find_first_not_of("0123456789", start) != std::string::npos)
        return (false);
    if (atof(this->_value.c_str()) > 2147483647 || atof(this->_value.c_str()) < -2147483648)
        return (false);
    return (true);
}

/**
 * @brief Check if the value is a double
 * Un double es del tipo 1.0
 * Tenemos que encontrar dónde está el punto
 * Antes del punto debe haber numeros y detrás también
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool Conversor::isDouble(std::string value)
{
    int start = 0;

    if (nbrOcurrences(value, '.') != 1 || nbrOcurrences(value, '-') > 1)
        return (false);
    if (value[0] == '-')
		start++;
    if (value.find_first_not_of("0123456789.", start) != std::string::npos)
        return (false);
    return (true);
}

/**
 * @brief Check if the value if a float
 * Un float es del tipo 1.0f
 * Miramos si tenemos un punto, un negativo y una f
 * Miramos si hay algo que sea diferente de 0123456789.f
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool Conversor::isFloat(std::string value)
{
    int start = 0;

    if (nbrOcurrences(value, '.') != 1 || nbrOcurrences(value, '-') > 1 || nbrOcurrences(value, 'f') != 1)
        return (false);
    if (value.find_first_not_of("-0123456789.f", start) != std::string::npos)
        return (false);
    if (value[value.length() - 1] != 'f')
        return (false);
    return (true);
}


/*
   GET PRIVATE ATRIBUTES
*/
std::string    Conversor::getValue()
{
    return (this->_value);
}

char    Conversor::getChar()
{
    return (this->_c);
}

int     Conversor::getInt()
{
    return (this->_d);
}

double  Conversor::getDouble()
{
    return (this->_ld);
}

float   Conversor::getFloat()
{
    return (this->_f);
}


/*
   CONVERSIONES
*/

/**
 * @brief Indicamos cuál es el valor de value en cada caso
 * 
 * @return std::string 
 */
std::string Conversor::getType( void )
{
    if (this->_value == "nan" || this->_value == "+inf" || this->_value == "-inf" || this->_value == "inf")
        return ("ld");
    if (this->_value == "nanf" || this->_value == "+inff" || this->_value == "-inff" || this->_value == "inff")
        return ("f");
    if (isChar(this->_value))
        return ("c");
    if (isInt(this->_value))
        return ("d");
    if (isFloat(this->_value))
        return ("f");
    if (isDouble(this->_value))
        return ("ld");
    throw ImpossibleException();
}

/**
 * @brief Convertimos a char
 * En caso de que sea un char, no tenemos que convertir nada
 * En caso de que lo que nos envían sea un int, convertimos a char con el static_cast
 * 
 * RECOGIDA = static_cast<A QUÉ LO QUIERES CASTEAR>(DE DÓNDE)
 * 
 */
void    Conversor::convertToChar( void )
{
    if (this->_type == "c") // char
        return ;
    else if (this->_type == "d") // int
        this->_c = static_cast<char>(this->_d);
    else if (this->_type == "f") // float
    {
        if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
            throw ImpossibleException();
        this->_c = static_cast<char>(this->_f);
    }
    else if (this->_type == "ld") // double
    {
        if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nan")
            throw ImpossibleException();
        this->_c = static_cast<char>(this->_ld);
    }
    else if (this->_type == "error")
        throw ImpossibleException();
    if (!isprint(this->_c))
        throw NonDisplayableException();
    // después de un throw puedo hacer un non-displayable exception????
}

/**
 * @brief Convertimos a int
 * En int no se ven el infinity, nanf, etc
 * 
 */
void    Conversor::convertToInt( void )
{
    if (this->_type == "c") // char
        this->_d = static_cast<int>(this->_c);
    else if (this->_type == "d") // int
        return ;
    else if (this->_type == "f") // float
    {
        if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nanf")
            throw ImpossibleException();
        if ((const int)this->_c >= INT_MAX || (const int)this->_c <= INT_MIN)
            throw ImpossibleException();
        this->_d = static_cast<int>(this->_f);
    }
    else if (this->_type == "ld") // double
    {
        if (this->_f == INFINITY || this->_f == -INFINITY || this->_value == "nan")
            throw ImpossibleException();
        this->_d = static_cast<int>(this->_ld);
    }
    else if (this->_type == "error")
        throw ImpossibleException();
}

/**
 * @brief Convertimos a double
 *  El float puede printar nanf, no hace falta llamar a la excepción
 */
void    Conversor::convertToDouble( void )
{
    if (this->_type == "c") // char
        this->_ld = static_cast<double>(this->_c);
    else if (this->_type == "d") // int
        this->_ld = static_cast<double>(this->_d);
    else if (this->_type == "f") // float
        this->_ld = static_cast<double>(this->_f);
    else if (this->_type == "ld") // double
        return ;
    else if (this->_type == "error")
        throw ImpossibleException();
}


/**
 * @brief Convertimos a float
 * El double puede printar nan, no hace falta llamar a la excepción
 * 
 */
void    Conversor::convertToFloat( void )
{
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

/**
 * @brief Lo que nos pasan es un string, aunque sea un char, int, double o float
 * Por eso, debemos convertirlo previamente al tipo que sea
 * c_str() retorna un puntero a un array (char *, no string)
 */
void    Conversor::convert( void )
{
    if (this->_type == "c") // char
        this->_c = _value[1];
    else if (this->_type == "d") // int
        this->_d = atoll(this->_value.c_str());
    else if (this->_type == "f") // float
        this->_f = atof(this->_value.c_str());
    else if (this->_type == "ld") // double
        this->_ld = atof(this->_value.c_str());
    else
        throw ImpossibleException();
}


/*
   EXCEPCIONES
*/
const char  *Conversor::ImpossibleException::what() const throw()
{
    return ("impossible");
}

const char  *Conversor::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}
