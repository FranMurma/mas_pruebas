/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:35:38 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/26 16:56:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	SCF : public AForm {
	private :
		std::string		_target;

	public :
		SCF(std::string target);
		~SCF();
		SCF(SCF const& copy);
		SCF&	operator=(SCF const& copy);
		std::string getTarget() const;
		void	execute(Bureaucrat const& executor) const;
};

std::ostream& operator <<(std::ostream& out, SCF const& obj);
