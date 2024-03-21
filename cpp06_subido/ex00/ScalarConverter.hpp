/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:02:31 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 17:43:11 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <iomanip>
# include <sstream>
# include <cstdlib>

class	ScalarConverter {
	private :
		std::string _type;
		std::string	_value;
		char		_c;
		long long	_d;
		double		_ld;
		float		_f;

	public :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(std::string value);
		ScalarConverter(ScalarConverter const& copy);
		ScalarConverter& operator=(ScalarConverter const& copy);
		//detectores
		bool		isChar(std::string value);
		bool		isInt(std::string value);
		bool		isFloat(std::string value);
		bool		isDouble(std::string value);
		bool		isPrintable(char c);
		bool		isInBorders();
		bool		hasDecimal() const;
		bool        hasDecimalf() const;
		//getters
		std::string getType();
		char		getChar();
		int			getInt();
		float		getFloat();
		double		getDouble();
		std::string	getValue();
		//converters
		void		convertToChar();
		void		convertToInt();
		void		convertToFloat();
		void		convertToDouble();
		void		convert();

		//Excepciones
		class	ImpossibleException : public std::exception {
			virtual const char *what() const throw();
		};
        class	NonDisplayableException : public std::exception {
            virtual const char *what() const throw();
		};
};

//Sobrecarga para imprimir
std::ostream& operator<<(std::ostream& out, ScalarConverter& obj);
