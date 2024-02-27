/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:40:23 by frmurcia          #+#    #+#             */
/*   Updated: 2024/02/21 15:31:41 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class	Form;

class	Bureaucrat {
	private :
		std::string	const	_name;
		int					_grade;
	public :
		Bureaucrat(std::string const name, int grade);
		~Bureaucrat();
		std::string getName() const;
		int	getGrade() const;
		Bureaucrat(Bureaucrat const& copy);
		Bureaucrat& operator=(Bureaucrat const& copy);
		void	promote();
		void	demote();
		void	signForm(Form& form);
		class	GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, Bureaucrat const& obj);
