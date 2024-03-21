/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:58 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/21 19:31:06 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>//Para los formatos de fecha
#include <map>

typedef std::pair<std::string, float> BitcoinData;

class BitcoinExchange {
	public :
		BitcoinExchange();
		void 	processInputFile(const std::string& inputFilename, std::vector<BitcoinData>& bitcoinData);
		~BitcoinExchange();
		bool	isValidDateFormat(const std::string& date);
		bool	isFloat(const std::string& str);
		bool	isPositive(const float& value);
		bool	isLessThanMaxInt(const float& value);
		float	getBitcoinValue(const std::string& date) const;
		void    processBitcoinDatabase(const std::string& databaseFilename);

	private :
		std::map<std::string, float> bitcoinDatabase;
//		void	loadBitcoinDatabase(const std::string& databaseFilename);
};


#endif // BITCOIN_EXCHANGE_HPP
