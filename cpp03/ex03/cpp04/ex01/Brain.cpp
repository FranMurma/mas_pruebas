/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:29:17 by frmurcia          #+#    #+#             */
/*   Updated: 2023/11/16 19:50:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "[Brain]: Default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "[Brain]: Default destructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++)
		this-> ideas[i] = other.ideas[i];
	std::cout << "[Brain]: Copy constructor called" << std::endl;
}

Brain& Brain::operator =(const Brain &other) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this-> ideas[i] = other.ideas[i];
		std::cout << "[Brain]: Coppied" << std::endl;
	}
	return (*this);
}

void	Brain::setIdea(int i, std::string idea) {
	this-> ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const {
	return (this->ideas[i]);
}

