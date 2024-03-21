/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:46:35 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/21 19:12:00 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
/*
int main() {
    // Nombre del archivo de entrada
    std::string inputFilename = "input.txt";

    // Contenedor para almacenar la información de bitcoin
    std::vector<BitcoinData> bitcoinData;

    // Crear un objeto BitcoinExchange
    BitcoinExchange bitcoinExchange;

    // Procesar el archivo de entrada
    bitcoinExchange.processInputFile(inputFilename, bitcoinData);

    // Imprimir la información de bitcoin almacenada en el contenedor
//    for (size_t i = 0; i < bitcoinData.size(); ++i) {
  //      std::cout <<  bitcoinData[i].first << " => " << bitcoinData[i].second << std::endl;
//    }

    return 0;

}*/

int main() {
    std::cout << "[BitcoinExchange] constructor called." << std::endl;

    // Creamos una instancia de BitcoinExchange
    BitcoinExchange exchange;

    // Nombre del archivo de la base de datos de Bitcoin
    std::string databaseFilename = "data.csv";

    // Procesamos la base de datos de Bitcoin
    exchange.processBitcoinDatabase(databaseFilename);

    // Ahora podemos realizar algunas pruebas de unidad para verificar si los datos se cargaron correctamente
    // Por ejemplo, podemos imprimir los precios de Bitcoin para algunas fechas específicas

    std::cout << "Bitcoin Prices:" << std::endl;

    std::vector<std::string> testDates;
    testDates.push_back("2011-01-03");
    testDates.push_back("2011-01-09");
    testDates.push_back("2001-42-42");
    testDates.push_back("2012-01-11");

    for (std::vector<std::string>::iterator it = testDates.begin(); it != testDates.end(); ++it) {
        const std::string& date = *it;
        float bitcoinValue = exchange.getBitcoinValue(date);
        std::cout << "Date: " << date << ", Bitcoin Value: " << bitcoinValue << std::endl;
    }

    std::cout << "[BitcoinExchange] destructor called." << std::endl;

    return 0;
}
