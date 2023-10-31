/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:12:43 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/23 16:20:24 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	getLevel(char **argv){
	int	i = 0;
	std::string	msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4)
	{
		if (argv[1] == msg[i])
			return (i);
		i++;
	}
	return (4);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
		std::cerr << "Error: You mut provide a level meesage as argument." << std::endl;
		std::cerr << "Use: " << argv[0] << " <level>" << std::endl;
		return (1); // 1 para indicar error
    }
	Harl miniharl;
    switch (getLevel(argv))
	{
		case 0:
			miniharl.complain("DEBUG");
		case 1:
			miniharl.complain("INFO");
		case 2:
			miniharl.complain("WARNING");
		case 3:
			miniharl.complain("ERROR");
			break ;
		default:
			std::cout << "Invalid message" <<std::endl;
	}
    return (0);
}
