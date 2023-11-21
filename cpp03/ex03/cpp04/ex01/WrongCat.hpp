/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:25 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/06 16:44:53 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal {
	public :
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat &operator =(const WrongCat &other);
		~WrongCat(void);
		void makeSound() const;
};

# endif
