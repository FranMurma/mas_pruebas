/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:12:43 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/21 12:20:17 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
		std::cerr << "Error: You mut provide a level meesage as argument." << std::endl;
		std::cerr << "Use: " << argv[0] << " <level>" << std::endl;
		return (1); // 1 para indicar error
    }

    Harl msj;
    msj.complain(argv[1]);
    return (0);
}
