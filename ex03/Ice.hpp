/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:24:40 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 19:47:25 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
	public :
		Ice(void);
		~Ice(void);
		Ice(const Ice &type);
		Ice &operator=(const Ice &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

# endif
