/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:53:30 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/27 16:28:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void    PhoneBook::AddContact(Contact NewContact)
{
	int	count = 0;

	if (size < 8)
	{
		agenda[size] = NewContact;
		agenda[size].saveIndex(size);
		size++;
	}
    else
    {
        while (count < 7)
        {
            agenda[count] = agenda[count + 1];
            agenda[count].saveIndex(count);
            count++;
        }
        agenda[7] = NewContact;
        agenda[7].saveIndex(7);
    }
}

int	PhoneBook::GetSize(void)
{
	return (size);
}

Contact	*PhoneBook::GetList(void)
{
	return (agenda);
}
