/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:13:17 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/26 19:36:09 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	RRF : public AForm {
	private :
		std::string		_target;

	public :
		RRF(std::string target);
		~RRF();
		RRF(RRF const& copy);
		RRF&	operator=(RRF const& copy);
		std::string getTarget() const;
		void	execute(Bureaucrat const& executor) const;
};
