/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:59:28 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/21 19:47:41 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

enum	e_type{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl{
	private :
		std::string	name;
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public :
		Harl();
		~Harl();
		void	complain( std::string level );
};

# endif
