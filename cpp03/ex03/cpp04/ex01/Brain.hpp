/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:47:42 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/06 18:51:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>

class	Brain {
	private :
		std::string ideas[100];
	public :
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator =(const Brain &other);
		void	setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};

# endif
