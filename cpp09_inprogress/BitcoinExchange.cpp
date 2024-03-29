/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:53 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/29 20:50:19 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange () {
	std::cout << "[BitcoinExchange] constructor called." << std::endl;
}

BitcoinExchange::~BitcoinExchange () {
	std::cout << "[BitcoinExchange] destructor called." << std::endl;
}

// Función para validar el formato de la fecha
bool	BitcoinExchange::isValidDateFormat(const std::string& date) {
	// Expresión regular para el formato AAAA-MM-DD
	std::regex dateRegex("\\d{4}-\\d{2}-\\d{2}");
	return (std::regex_match(date, dateRegex));
}

bool	BitcoinExchange::isFloat(const std::string& str) {//Booleano que coge la string y comprueba que sea asimilable a un float
    std::istringstream iss(str);//lee datos de una string como si fueran datos de entrada desde un flujo de entrada estándar
    float f;
	//extrae el valor de iss y lo almacena en f. std::noskipws indica que no se deben omitir los espacios en blanco
	//iss.eof()   devuelve verdadero si se ha alcanzado el final del flujo de entrada (iss). 
	//!iss.fail() devuelve verdadero Si hay algún problema con la conversión del texto a un número decimal de punto flotante.
    return (iss >> std::noskipws >> f) && iss.eof() && !iss.fail();
}

bool BitcoinExchange::isPositive(const float& amount) {
    return (amount > 0);
}

bool BitcoinExchange::isLessThanMaxInt(const float& amount) {
    return (amount < std::numeric_limits<int>::max());
}

bool BitcoinExchange::isValidDataLine(const std::string& line) {
	std::istringstream	iss(line);
	std::string	date;
	float	amount;
	char	delimiter;
	// Intentar extraer una fecha y un valor de la línea
	if (iss >> date >> delimiter >> amount) {
		// Verificar si la fecha y el valor son válidos
		if (isValidDateFormat(date) && isFloat(std::to_string(amount)))
			return (true); // La línea contiene datos computables
	}
	return (false); // La línea no contiene datos computables
}

void BitcoinExchange::processInputFile(const std::string& inputFilename, std::vector<BitcoinData>& bitcoinData) {
	std::ifstream inputFile(inputFilename);//ifstream lee desde archivos, istringstream desde strings de caracteres.
	//inputFile es el nombre del objeto de flujo de archivo que hemos creado
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open the file " << inputFilename << std::endl;
		return;
	}
	std::string line;
	bool firstLine = true;
	while (std::getline(inputFile, line)) {//Leemos el objeto de flujo creado a partir del fichero
		if (firstLine) {//Nos saltamos la primera linea, que tiene la cabecera (date | amount)
			if (!isValidDataLine(line) && firstLine) {
				continue;
			}
			firstLine = false;
		}
		std::istringstream iss(line);// leemos desde el string line con istringstream
		std::string	date;
		std::string	amount_str;
		char	delimiter;
		if (iss >> date >> delimiter >> amount_str) {//Con cada linea llenamos date, delimiter y amount.
			float amount = std::stof(amount_str);
			if (delimiter != '|') {
				std::cerr << "Error: Bad delimiter => " << delimiter << std::endl;
				continue;
			}
			if (!isFloat(std::to_string(amount))) {
				std::cerr << "Error: Bad value for the amount => " << amount << std::endl;
				continue;
			}
			if (!isPositive(amount)) {
				std::cerr << "Error: Not a positive number => " << amount << ". Line: " << line << std::endl;
				continue;
			}
			if (!isLessThanMaxInt(amount)) {
				std::cerr << "Error: too large a number. Line: " << line << std::endl;
				continue;
			}
			if (!isValidDateFormat(date)) {
				std::cerr << "Error: bad input. Bad date => " << date << ". Line " << line << std::endl;
				continue;
			}
			bitcoinData.push_back(std::make_pair(date, amount));//llenamos el vector con data y amount (delimiter solo marca)
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	inputFile.close();
}

// VAMOS A METER AQUI LOS CHEQUEOS EN LUGAR DE EN LA OTRA
void BitcoinExchange::processBitcoinDatabase(const std::string& databaseFilename) {
	std::ifstream databaseFile(databaseFilename);
	if (!databaseFile.is_open()) {
		std::cerr << "Error: Cannot open the file " << databaseFilename << std::endl;
		return;
	}
	std::string line;
	bool	firstLine = true;
	while (std::getline(databaseFile, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string str_price;
		float	price;
		if (firstLine) {//Nos saltamos la primera linea, que tiene la cabecera (date | value)
			if (!isValidDataLine(line) && firstLine) {
				firstLine = false;
				continue;
			}
			firstLine = false;
		}
		if (std::getline(iss, date, ',') && (iss >> str_price)) {
			price = std::stof(str_price);
			bitcoinDatabase[date] = price; // Almacena el precio de Bitcoin en el mapa
		}
		else
			std::cerr << "Error: Incorrect format in the line: " << line << std::endl;
	}
	databaseFile.close();
}

/*
float BitcoinExchange::getBitcoinValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = bitcoinDatabase.lower_bound(date); // Busca la primera fecha igual o posterior a la fecha dada
    if (it != bitcoinDatabase.begin() && it != bitcoinDatabase.end()) {
        while (it->first != date) {
            --it; // Si la fecha encontrada no es la misma que la buscada, retrocede una posición
        }
        return it->second;
    } else {
        if (it == bitcoinDatabase.end()) {
            std::cerr << "Warning: No Bitcoin value found for dates after " << bitcoinDatabase.rbegin()->first << ". Using the closest available value." << std::endl;
            return bitcoinDatabase.rbegin()->second; // Devuelve el último valor de Bitcoin disponible
        } else {
            std::cerr << "Warning: No Bitcoin value found for dates before " << bitcoinDatabase.begin()->first << ". Using the earliest available value." << std::endl;
            return bitcoinDatabase.begin()->second; // Devuelve el primer valor de Bitcoin disponible
        }
    }
}*/

float BitcoinExchange::getBitcoinValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = bitcoinDatabase.lower_bound(date); // Busca la primera fecha igual o posterior a la fecha dada
	if (bitcoinDatabase.empty() || it == bitcoinDatabase.begin()) {
    std::cerr << "Warning: No Bitcoin value found for dates before " << it->first << ". Using 0 value." << std::endl;
    return it->second; // Devuelve el valor asociado a la fecha más antigua en el mapa
}
    if (it == bitcoinDatabase.begin()) {
        std::cerr << "Warning: No Bitcoin value found for dates before " << it->first << ". Using the earliest available value." << std::endl;
        return it->second; // Devuelve el valor asociado a la fecha más antigua en el mapa
    }
    if (it != bitcoinDatabase.end() && it != bitcoinDatabase.end()) {
		if (it->second == 0) {
			--it;
		}
		return it->second;
	}
	else {
		  if (it == bitcoinDatabase.end()) {
			  std::cerr << "Warning: No Bitcoin value found for dates after " << bitcoinDatabase.rbegin()->first << ". Using the closest available value." << std::endl;
			  return bitcoinDatabase.rbegin()->second; // Devuelve el último valor de Bitcoin disponible
			  }
		  else {
			  std::cerr << "Warning: No Bitcoin value found for dates before " << bitcoinDatabase.begin()->first << ". Using the earliest available value." << std::endl;
			  return bitcoinDatabase.begin()->second; // Devuelve el primer valor de Bitcoin disponible
		  }
	}
}
//	}
//
//		std::cout << "La fecha es correcta\n";
//      return it->second; // Devuelve el valor de Bitcoin si la fecha coincide exactamente
//}
//	else if (it != bitcoinDatabase.begin()) {
//		std::cout << "La fecha es incorrecta, retroccedemos\n";
//        --it; // Retrocede una posición para obtener la fecha más cercana anterior
//        return it->second;
//    } else {
//        std::cerr << "Warning: No Bitcoin value found for dates before " << bitcoinDatabase.begin()->first << ". Using the earliest available value." << std::endl;
//        return bitcoinDatabase.begin()->second; // Devuelve el primer valor de Bitcoin disponible
//    }
//}
