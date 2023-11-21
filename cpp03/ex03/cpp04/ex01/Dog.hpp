/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:09:28 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 19:16:57 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private :
		Brain* _brain;

	public :
		Dog(void);
		~Dog(void);
		Dog(const Dog &other);
		Dog &operator =(const Dog &other);
		void makeSound() const;
};

# endif
