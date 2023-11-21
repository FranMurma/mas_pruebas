/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:37:31 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 19:34:52 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
	private :
		Brain* _brain;

	public :
		Cat(void);
		Cat(const Cat &other);
		Cat &operator =(const Cat &other);
		~Cat(void);
		void	makeSound() const;
};

# endif
