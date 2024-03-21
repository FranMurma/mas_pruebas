/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:53 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/21 19:55:52 by frmurcia         ###   ########.fr       */
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
bool BitcoinExchange::isValidDateFormat(const std::string& date) {
	// Expresión regular para el formato AAAA-MM-DD
	std::regex dateRegex("\\d{4}-\\d{2}-\\d{2}");
	return (std::regex_match(date, dateRegex));
}

bool BitcoinExchange::isFloat(const std::string& str) {
    std::istringstream iss(str);
    float f;
    return (iss >> std::noskipws >> f) && iss.eof() && !iss.fail();
}

bool BitcoinExchange::isPositive(const float& value) {
    return (value > 0);
}

bool BitcoinExchange::isLessThanMaxInt(const float& value) {
    return (value < std::numeric_limits<int>::max());
}

void BitcoinExchange::processInputFile(const std::string& inputFilename, std::vector<BitcoinData>& bitcoinData) {
	std::ifstream inputFile(inputFilename);//ifstream lee desde archivos, istringstream desde cadenas de caracteres.
	//inputFile es el nombre del objeto de flujo de archivo que hemos creado
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open the file " << inputFilename << std::endl;
        return;
	}
	std::string line;
	bool firstLine = true;
	while (std::getline(inputFile, line)) {//Leemos el objeto de flujo creado a partir del fichero
		if (firstLine) {//Nos saltamos la primera linea, que tiene la cabecera (date | value)
			firstLine = false;
			continue;
		}
		std::istringstream iss(line);// leemos desde el string line con istringstream
		std::string	date;
		float	value;
		char	delimiter;
		if (iss >> date >> delimiter >> value) {//Con cada linea llenamos date, delimiter y value.
			if (!isFloat(std::to_string(value))) {
				std::cerr << "Error: Bad value => " << value << std::endl;
				continue;
			}
			if (!isPositive(value)) {
				std::cerr << "Error: Not a positive number => " << value << ". Line: " << line << std::endl;
				continue;
			}
			if (!isLessThanMaxInt(value)) {
				std::cerr << "Error: too large a number. Line: " << line << std::endl;
				continue;
			}
			if (!isValidDateFormat(date)) {
				std::cerr << "Error: bad input. Bad date => " << date << ". Line " << line << std::endl;
				continue;
			}
			bitcoinData.push_back(std::make_pair(date, value));//llenamos el vector con data y value (delimiter solo marca)
			float bitcoinValue = bitcoinDatabase[date];
			std::cout << date << " => " << value << " = " << (value * bitcoinValue) << std::endl;
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	inputFile.close();
}

void BitcoinExchange::processBitcoinDatabase(const std::string& databaseFilename) {
    std::ifstream databaseFile(databaseFilename);
    if (!databaseFile.is_open()) {
        std::cerr << "Error: Cannot open the file " << databaseFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(databaseFile, line)) {
        std::istringstream iss(line);
        std::string date;
        float price;
        if (std::getline(iss, date, ',') && (iss >> price)) {
            bitcoinDatabase[date] = price; // Almacena el precio de Bitcoin en el mapa
        } else {
            std::cerr << "Error: Incorrect format in the line: " << line << std::endl;
        }
    }

    databaseFile.close();
}

/*
float BitcoinExchange::getBitcoinValue(const std::string& date) const {
    // Busca el precio de Bitcoin correspondiente a la fecha dada o la fecha más cercana anterior en el archivo CSV
    std::map<std::string, float>::const_iterator it = bitcoinDatabase.lower_bound(date);

    if (it != bitcoinDatabase.begin() && it == bitcoinDatabase.end()) {
        // Si la fecha no es encontrada y es mayor que todas las fechas en el archivo CSV
        --it; // Retrocede al último elemento en el mapa
    } else if (it != bitcoinDatabase.begin() && it != bitcoinDatabase.end()) {
        // Si la fecha no es encontrada y es entre dos fechas en el archivo CSV
        const std::string& date1 = it->first;
        --it; // Retrocede al elemento anterior en el mapa
        const std::string& date2 = it->first;

        // Comparamos qué fecha está más cercana a la fecha dada
        if (date.compare(date1) - date.compare(date2) > 0) {
            // La fecha2 es más cercana
            it = bitcoinDatabase.find(date2);
        } else {
            // La fecha1 es más cercana
            it = bitcoinDatabase.find(date1);
        }
    }

    if (it != bitcoinDatabase.end()) {
        return it->second;
    } else {
        std::cerr << "Error: Bitcoin value not found for the date " << date << std::endl;
        return 0.0; // O devuelve un valor predeterminado en caso de no encontrar el precio
    }
}*/

float BitcoinExchange::getBitcoinValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = bitcoinDatabase.lower_bound(date); // Busca la primera fecha igual o posterior a la fecha dada
    if (it != bitcoinDatabase.begin() && it != bitcoinDatabase.end()) {
        if (it->first != date) {
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
}
