/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:20:45 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/19 14:51:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

class ValueNotFoundException : public std::exception {
	public :
		virtual const char* what() const throw() {
			return "Error: Value not found.";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
		if (iter == container.end())
			throw ValueNotFoundException();
	return (iter);
}

# endif
