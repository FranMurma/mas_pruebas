/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:36:48 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/15 19:12:22 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <type_traits>

template <typename T>
void	swap(T& a, T& b) {
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b) {
	return (a < b) ? a : b;
}

template <typename T>
T	max(T a, T b) {
	return (a > b) ? a : b;
}

# endif
