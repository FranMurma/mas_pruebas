/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:39:53 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/29 17:21:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	PPF : public AForm {
	private :
		std::string		_target;

	public :
		PPF(std::string target);
		~PPF();
		PPF(PPF const& copy);
		PPF&	operator=(PPF const& copy);
		std::string getTarget() const;
		void	execute(Bureaucrat const& executor) const;
};
