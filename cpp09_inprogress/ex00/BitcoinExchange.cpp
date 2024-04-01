/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:53 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/01 13:56:10 by frmurcia         ###   ########.fr       */
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

bool	BitcoinExchange::isPositive(const float& amount) {
    return (amount > 0);
}

bool	BitcoinExchange::isLessThanMaxInt(const float& amount) {
    return (amount < std::numeric_limits<int>::max());
}

bool	BitcoinExchange::isValidDataLine(const std::string& line) {
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

/*******
 * Funcion que lee input.txt o el fichero que sea y lo va a comparar con la base de datos.
 * ***/
void BitcoinExchange::processInputFile(const std::string& inputFilename, std::vector<BitcoinData>& bitcoinData) {
	std::ifstream inputFile(inputFilename);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open the file " << inputFilename << std::endl;
		return;
	}
	std::string line;
	bool    firstLine = true;
	while (std::getline(inputFile, line)) {
		std::istringstream	iss(line);
		std::string	date;
		char	delimiter;
		float	amount;
		// Intentar extraer una fecha, un delimitador y un valor de la línea
		if (iss >> date >> delimiter >> amount) {
			// Verificar si el delimitador es válido
			if (delimiter != '|') {
				std::cerr << "Error: Bad delimiter => " << delimiter << std::endl;
				continue; // Ir a la próxima línea
				}
			// Verificar si el valor es válido
			if (!isFloat(std::to_string(amount))) {
				std::cerr << "Error: Bad value for the amount => " << amount << std::endl;
				continue; // Ir a la próxima línea
				}
			if (!isPositive(amount)) {
				std::cerr << "Error: Not a positive number => " << amount << ". Line: " << line << std::endl;
				continue; // Ir a la próxima línea
				}
			if (!isLessThanMaxInt(amount)) {
				std::cerr << "Error: too large a number. Line: " << line << std::endl;
				continue; // Ir a la próxima línea
				}
			if (!isValidDateFormat(date)) {
				std::cerr << "Error: bad input. Bad date => " << date << ". Line " << line << std::endl;
				continue; // Ir a la próxima línea
				}
			if (date.length() == 0 || amount == 0 ) {
				std::cerr << "Error: bad input. Line " << line << std::endl;
				continue;
			}
			// Si la línea es válida, almacenar los datos en el vector bitcoinData
			bitcoinData.push_back(std::make_pair(date, amount));
			// Calcular y mostrar el resultado
			float bitcoinValue = getBitcoinValue(date);
			if (bitcoinValue != -1) {
				std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(2) << static_cast<double>(amount * bitcoinValue) << std::endl;
			}
		}
		else {
			if (firstLine) {//Nos saltamos la primera linea, que tiene la cabecera (date | value)
				firstLine = false;
				if (!isValidDataLine(line))
					continue;
			}

			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	inputFile.close();
}

// Funcion para crear la base de datos con el fichero csv
// ******************************************************
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

/****************
 * getBitcoinValue  Utiliza el mapa bitcoinDatabase para buscar la fecha dada y devuelve el valor asociado a esa fecha en el mapa. 
 * Si la fecha exacta no está presente en el mapa, busca la fecha más cercana anterior y devuelve su valor asociado. 
 * Si no se encuentra ninguna fecha anterior en el mapa, se emite un mensaje de advertencia y se devuelve el valor asociado 
 * a la fecha más reciente en el mapa.


float BitcoinExchange::getBitcoinValue(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = bitcoinDatabase.lower_bound(date);
	// Busca la primera fecha igual o posterior a la fecha dada
	if (it == bitcoinDatabase.begin()) {
		std::cout << "Date = " << date << std::endl;
		std::cout << "it->first = " <<  it->first << std::endl;
		if (date == it->first)
			return (bitcoinDatabase.begin()->second);
		else {
			std::cerr << "Warning: No Bitcoin value found for dates before " << it->first 
				<< ". Date = " << date << std::endl;
			return 0.0f;
	   }
	}
	if (it != bitcoinDatabase.begin() && it != bitcoinDatabase.end()) {
		if (it->first != date) {
			it--;
		}
		return (it->second);
	}
	else {
		if (it == bitcoinDatabase.end()) {
			std::cerr << "Warning: No Bitcoin value found for dates after " << bitcoinDatabase.rbegin()->first 
				<< ". Using the closest available value." << std::endl;
			// Devuelve el último valor de Bitcoin disponible. Lo contratio a .begin()
			return (bitcoinDatabase.rbegin()->second);
		}
		else
			return (bitcoinDatabase.begin()->second); // Devuelve el primer valor de Bitcoin disponible
	}
}*/

float BitcoinExchange::getBitcoinValue(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = bitcoinDatabase.lower_bound(date);
    // Si la fecha exacta se encuentra en el mapa, y es menor que la ultima, devuelve su valor
	if (it->first == date)
        return (it->second);
    // Si la fecha está antes de la primera fecha en el mapa
    if (date < bitcoinDatabase.begin()->first) {
        std::cerr << "Warning: No Bitcoin value found for dates before " << it->first
                  << ". Date = " << date << std::endl;
        return (-1); // O cualquier otro valor que indique un error
    }
	if (date == bitcoinDatabase.end()->first) {
		return (it->second);
	}
	if (date > bitcoinDatabase.rbegin()->first) {
		std::cout << "Warning: No Bitcoin value found for dates after " << bitcoinDatabase.rbegin()->first
			<< ". Using the last available value (" << bitcoinDatabase.rbegin()->second << "):" << std::endl;
	}
    it--;
    return (it->second);
}




/*****************
 * Deberes: No imprimir valores mayores que el max int.
 * Resolver: std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(2) << static_cast<double>(a
 * o sea, la impresion en double en lugar de en floats
 *
 * ***************/
