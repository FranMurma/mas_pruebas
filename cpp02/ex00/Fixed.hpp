/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:44:44 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/30 19:16:39 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
	private :
		int	intVal;
		static const int	fraccional = 8;
	public :
		Fixed (void);
		~Fixed (void);
		Fixed (Fixed const &copy); //Constructor de copia: &copy = objeto a copiar
		Fixed &operator= (Fixed const &copy);
        int		getRawBits( void ) const;
        void	setRawBits ( int const raw );
};

# endif
