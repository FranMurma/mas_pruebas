/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:20:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/21 13:19:06 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

bool	IsDigit(std::string str)
{
	std::string::size_type count = 0;

	while (count < str.length())
	{
		if (!((str[count] >= '0' && str[count] <= '9') || str[count] == ' '))
			return (false);
		count++;
	}
	return (true);
}

bool	IsOnlySpaces(std::string str)
{
	std::string::size_type count = 0;

	while (count < str.length())
	{
		if (str[count] != ' ')
			return (true);
		count++;
	}
	return (false);
}

bool	IsCharacter(std::string str)
{
	std::string::size_type count = 0;

	while (count < str.length())
	{
		if (!((str[count] >= 'A' && str[count] <= 'Z') || (str[count] >= 'a' && str[count] <= 'z') || str[count] == ' '))
			return (false);
		count++;
	}
	return (true);
}

void CleanString(std::string &str) {
    // Eliminar espacios en blanco dobles
    size_t c = 0;
    while (c < str.length() - 1) {
		if (str[c] == '\t')
			str[c] = ' ';
        if (str[c] == ' ' && str[c + 1] == ' ') {
            str.erase(c, 1);
        } else {
            c++;
        }
    }
    // Eliminar espacio en blanco al principio, si existe
    if (str[0] == ' ') {
        str.erase(0, 1);
    }
    // Eliminar espacio en blanco al final, si existe
    if (str[str.length() - 1] == ' ') {
        str.erase(str.length() - 1, 1);
    }
}

std::string	ShortString(const std::string& input) 
{
	std::string::size_type	spaces = 10 - input.length();
	std::string::size_type	i = 0;
	if (input.length() > 10)
		return input.substr(0, 9) + ".";
	else if (input.length() <= 10)
    {
	    std::string result(10, ' '); // Crea una cadena de 10 espacios en blanco
		while(spaces > 0 && i < input.length())
			result[spaces++] = input[i++];
		return (result);
	}
	else
		return (input);
}

void    PrintContact(Contact Contact)
{
    std::cout << "First name: " << Contact.getFirstName() << "\n";
    std::cout << "Last name: " << Contact.getLastName() << "\n";
    std::cout << "Nickname: " << Contact.getNickName() << "\n";
    std::cout << "Phone number: " << Contact.getPhoneNumber() << "\n";
//	std::cout << "Darkest secret: " << Contact.getDarkestSecret() << "\n";
}

void    PrintShort(Contact Contact)
{
	std::cout << "Index:  " << Contact.getIndex() << "|";
    std::cout << "First name: " << ShortString(Contact.getFirstName()) << "|";
    std::cout << "Last name: " << ShortString(Contact.getLastName()) << "|";
    std::cout << "Nickname: " << ShortString(Contact.getNickName()) << "|\n";
}

void	ft_add(PhoneBook *List)
{
	std::string setFirstName, setLastName, setNickName, setPhoneNumber, setDarkestSecret;

	std::cout << "Enter First Name:	";
	    while (true) {
        if (!std::getline(std::cin, setFirstName)) {
            std::cout << "Ctrl-D. Closing program..." << std::endl;
            exit(0);
        }
		if (!setFirstName.empty())
			CleanString(setFirstName);
        if (IsCharacter(setFirstName) && !setFirstName.empty() && IsOnlySpaces(setFirstName)) {
            break;  // La entrada es válida, sal del bucle.
        }
        std::cout << "Please, enter letters: ";
		}
		std::cout << "Enter Last Name:	";
	    while (true) {
        if (!std::getline(std::cin, setLastName)) {
            std::cout << "Ctrl-D. Closing program..." << std::endl;
            exit(0);
        }
		if (!setLastName.empty())
			CleanString(setLastName);
        if (IsCharacter(setLastName) && !setLastName.empty() && IsOnlySpaces(setLastName)) {
            break;  // La entrada es válida, sal del bucle.
        }
        std::cout << "Please, enter letters: ";
		}
		std::cout << "Enter Nick Name:	";
		while (true) {
        if (!std::getline(std::cin, setNickName)) {
            std::cout << "Ctrl-D. Closing program..." << std::endl;
            exit(0);
        }
		if (!setNickName.empty())
			CleanString(setNickName);
        if (!setNickName.empty() && IsOnlySpaces(setNickName)) {
            break;  // La entrada es válida, sal del bucle.
        }
        std::cout << "Please, enter your Nick Name: ";
		}
		std::cout << "Enter Phone Number:	";
		while (true) {
        if (!std::getline(std::cin, setPhoneNumber)) {
            std::cout << "Ctrl-D. Closing program..." << std::endl;
            exit(0);
        }
		if (!setPhoneNumber.empty())
			CleanString(setPhoneNumber);
		if (IsDigit(setPhoneNumber) && !setPhoneNumber.empty() && IsOnlySpaces(setLastName)) {
            break;  // La entrada es válida, sal del bucle.
        }
		std::cout << "Please, enter numbers: ";
		}
		std::cout << "Enter Darkest Secret:	";
		while (true) {
        if (!std::getline(std::cin, setDarkestSecret)) {
            std::cout << "Ctrl-D. Closing program..." << std::endl;
            exit(0);
        }
		if (!setDarkestSecret.empty())
			CleanString(setDarkestSecret);
        if (!setDarkestSecret.empty() && IsOnlySpaces(setLastName)) {
            break;  // La entrada es válida, sal del bucle.
        }
        std::cout << "enter your Darkest Secret!: ";
		}
	

	Contact newContact(setFirstName, setLastName, setNickName, setPhoneNumber, setDarkestSecret);
	List->AddContact(newContact);
}

void	ft_search(PhoneBook *List)
{
    std::stringstream ss;
    std::string input;

    if (List->GetSize() == 0)
	{
        std::cout << "\nYour phonebook is empty!\nPlease, enter return\n" << std::endl;
        return;
    }
	std::cout << "----------------------------------------------------------------------------------\n";

    int index = 0;
    while (index < List->GetSize()) 
	{
        PrintShort(List->GetList()[index]);
        index++;
    }

    std::cout << "----------------------------------------------------------------------------------\n\n";

	int contactIndex;
	int	x = List->GetSize();
	std::cout << "Insert the contact number: ";
	while (true)
	{
		if (!std::getline(std::cin, input)) {
            std::cout << "Ctrl-D. Closing program..." << std::endl;
            exit(0);
		}
		if (!input.empty())
			CleanString(input);
		if (input.length() == 1 && input[0] >= '1' && input[0] <= ('0' + x))
		{
			contactIndex = input[0] - '0'; // Convertir el carácter en un número
			if (contactIndex >= 1 && contactIndex <= List->GetSize())
			{
				PrintContact(List->GetList()[contactIndex - 1]);
				std::cout <<"\nPress enter to continue...";
				break ;
			}
		}
		else
		{
			std::cout << "Please, write a valid contact number:   ";
		}
	}
}

void    ft_menu()
{
    std::cout << "\n+--------------------+\n";
    std::cout << "|---------ADD--------|\n";
    std::cout << "|--------SEARCH------|\n";
    std::cout << "|---------EXIT-------|\n";
    std::cout << "+--------------------+\n\n";
	std::cout << "\nPlease, type your option in uppercase>	";
}

int	main(void)
{

	std::string input = "";
	PhoneBook List;
	
	ft_menu();
	while (std::cin)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			ft_add(&List);
			ft_menu();
		}
		else if (input == "SEARCH")
			ft_search(&List);
		else if (input == "EXIT")
		{
			std::cout << "closing program\n";
			exit (0);
		}
		else
			ft_menu();
	}
	if (!std::getline(std::cin, input))
	{
		std::cout << "Ctrl-D. Closing program..." << std::endl;
		return (0);
	}
}
