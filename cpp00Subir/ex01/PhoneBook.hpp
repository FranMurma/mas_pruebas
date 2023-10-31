/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:14:42 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/26 19:37:50 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	agenda[8];
		int		size;
    public:
		PhoneBook(void);
			~PhoneBook(void);
		void	AddContact(Contact NewContact);
		int		GetSize(void);
		Contact	*GetList(void);
};

#endif
