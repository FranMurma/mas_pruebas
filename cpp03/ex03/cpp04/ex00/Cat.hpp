/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:37:31 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 16:55:45 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
	public :
		Cat(void);
		Cat(const Cat &other);
		Cat &operator =(const Cat &other);
		~Cat(void);
		void	makeSound() const;
};

# endif
