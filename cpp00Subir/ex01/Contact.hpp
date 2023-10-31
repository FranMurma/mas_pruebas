/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:03:00 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/29 19:01:38 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	unsigned int	Index;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;

public:
	Contact(void);
		~Contact(void);

	Contact(std::string setFirstName, std::string setLastName, std::string setNickName, std::string setPhoneNumber, std::string setDarkestSecret);
	
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	int		getIndex(void);
	void	saveIndex(int oldIndex);
};

#endif
