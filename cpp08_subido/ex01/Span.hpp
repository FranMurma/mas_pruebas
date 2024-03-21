/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:03:53 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/19 18:35:35 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class	Span {
	private :
		unsigned int		capacity;
		std::vector<int>	elements;

	public :
		Span(unsigned int capacity);
		~Span();
		Span(Span const& copy);
		Span& operator=(Span const& copy);
		void			addNumber(int number);
		long long int	shortestSpan() const;
		long long int	longestSpan() const;
};

class	FullVectorException : public std::exception {
	public :
		virtual const char* what() const throw() {
			return ("Error: Full vector, we cannot add more numbers.");
		}
};

class	NotEnoughElementsException : public std:: exception {
	public :
		virtual const char *what() const throw() {
			return ("Error: Not enought elements to have a range.");
		}
};

# endif
