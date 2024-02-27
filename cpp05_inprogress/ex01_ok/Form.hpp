/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:25 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/21 15:22:40 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class	Form {
	private :
		std::string const	_name;
		bool				_is_signed;//Si esta firmado
		int const			_r_gradeS;//Grado requerido para ser firmado
		int const			_r_gradeE;//Grado requerido para ser ejecutado

	public :
		Form(std::string const name, int const r_gradeS, int const r_gradeE);
		~Form();
		Form(Form const& copy);
		Form& operator=(Form const& copy);

		std::string getName() const;
		int			get_rGradeS() const;
		int         get_rGradeE() const;
		bool		get_isSigned() const;

		void		beSigned(Bureaucrat &bureaucrat);//Cambia el booleano is_signed si el burocrata puede firmarlo
	   	
		class	GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, Form const& obj);
