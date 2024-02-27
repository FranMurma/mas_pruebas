/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:25 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/27 16:33:03 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class	AForm {
	private :
		std::string const	_name;
		bool				_is_signed;//Si esta firmado
		int const			_r_gradeS;//Grado requerido para ser firmado
		int const			_r_gradeE;//Grado requerido para ser ejecutado

	protected :
        void            checkExecute(int grade) const;// protected porque es auxiliar

	public :
		AForm(std::string const name, int const r_gradeS, int const r_gradeE);
		~AForm();
		AForm(AForm const& copy);
		AForm& operator=(AForm const& copy);

		std::string getName() const;
		int				get_rGradeS() const;
		int				get_rGradeE() const;
		bool			get_isSigned() const;

		void			beSigned(Bureaucrat &bureaucrat);//Cambia el booleano is_signed si el burocrata puede firmarlo
		virtual void	execute(Bureaucrat const& executor) const = 0;
	   	
		class	GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	ExecutedFormException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	SignFormException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, AForm const& obj);
