/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:46:35 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/29 18:14:47 by frmurcia         ###   ########.fr       */
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


#include <iostream>
#include <vector>
#include "BitcoinExchange.hpp"

int main() {
    // Crear una instancia de BitcoinExchange
    BitcoinExchange exchange;

    // Procesar la base de datos de Bitcoin
    std::string databaseFilename = "data.csv";
    exchange.processBitcoinDatabase(databaseFilename);

    // Procesar el archivo de entrada con las fechas y valores de Bitcoin
    std::vector<std::pair<std::string, float> > bitcoinData;
    std::string inputFilename = "input.txt";
    exchange.processInputFile(inputFilename, bitcoinData);

    // Imprimir los resultados
    std::cout << "Bitcoin Prices:" << std::endl;
    for (std::vector<std::pair<std::string, float> >::const_iterator it = bitcoinData.begin(); it != bitcoinData.end(); ++it) {
        const std::string& date = it->first;
        float value = it->second;
        float bitcoinValue = exchange.getBitcoinValue(date);
        std::cout << date << " => " << value << " = " << (value * bitcoinValue) << std::endl;
    }
    return 0;
}
