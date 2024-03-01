/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:37:23 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/01 16:07:48 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern {
	private :
		
		PPF	*makePPF(std::string formName, std::string formTarget) const;
		RRF	*makeRRF(std::string formName, std::string formTarget) const;
		SCF	*makeSCF(std::string formName, std::string formTarget) const;

	public :
		//clase canonica: constructor, destructor, copia, sobrecarga
		Intern();
		~Intern();
		Intern(Intern const& copy);
		Intern& operator=(Intern const& copy);
		//Metodos
		AForm	*makeForm(std::string formName, std::string formTarget) const;
		//Exception
        class IncorrectFormException :  public std::exception {
			public :
				virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Intern& form);

# endif
