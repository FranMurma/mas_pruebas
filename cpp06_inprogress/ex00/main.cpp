/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:01:42 by frmurcia          #+#    #+#             */
/*   Updated: 2024/03/07 17:01:44 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversor.hpp"

bool isError(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (true);
    }
    std::string param(argv[1]);
    if (param.empty())
    {
        std::cerr << "I cannot cast the nothing" << std::endl;
        return (true);
    }
    return (false);
}

// char, int, float or double
int main(int argc, char **argv)
{
    if (isError(argc, argv))
        return (-1);
    try
    {
        Conversor conversor = Conversor(argv[1]);
        std::cout << conversor << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    return (0);
}
