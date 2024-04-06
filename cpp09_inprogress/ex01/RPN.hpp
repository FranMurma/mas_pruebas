/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:04:49 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/03 20:31:17 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class	RPNCalculator {
	private :
		int	convertToInt(const std::string& str) const;

	public :
		int			evaluateExpression(const std::string& expression) const;
		bool		isInteger(const std::string& str) const;
};

std::string normalizeInput(const std::string& input);

# endif
