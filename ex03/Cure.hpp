/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:58:14 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/21 18:54:36 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
	public :
		Cure(void);
		~Cure(void);
		Cure(const Cure &type);
		Cure &operator=(const Cure &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

# endif
