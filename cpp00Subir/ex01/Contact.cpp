/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:51:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/27 16:28:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

Contact::Contact(std::string setFirstName, std::string setLastName, std::string setNickName, std::string setPhoneNumber, std::string setDarkestSecret)
{
	FirstName = setFirstName;
	LastName = setLastName;
	NickName = setNickName;
	PhoneNumber = setPhoneNumber;
	DarkestSecret = setDarkestSecret;
}

std::string Contact::getFirstName()
{
	return (FirstName);
}

std::string Contact::getLastName()
{
	return (LastName);
}

std::string Contact::getNickName()
{
	return (NickName);
}

std::string Contact::getPhoneNumber()
{
	return (PhoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (DarkestSecret);
}

int	Contact::getIndex(void)
{
	return (Index);
}

void	Contact::saveIndex(int oldIndex)
{
	Index = oldIndex + 1;
}
