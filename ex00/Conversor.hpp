/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:02:31 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/07 19:24:07 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class	Conversor {
	private :
		std::string _type;
		std::string	_value;
		char		_c;
		int			_d;
		double		_ld;
		float		_f;

	public :
		Conversor();
		~Conversor();
		Conversor(std::string value);
		Conversor(Conversor const& copy);
		Conversor& operator=(Conversor const& copy);
		//detectores
		bool		isChar(std::string value);
		bool		isInt(std::string value);
		bool		isFloat(std::string value);
		bool		isDouble(std::string value);
		bool		isPrintable(char c);
		bool		isInBorders();
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
std::ostream& operator<<(std::ostream& out, Conversor& obj);
