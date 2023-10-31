/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:12:06 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/23 16:19:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void	Harl::debug( void ){
	std::cout <<"I love having extra bacon for my 7XL-double-cheese-triple-pickle- special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ){
	std::cout <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<std::endl;
}

void	Harl::warning( void ){
	std::cout <<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<std::endl;
}

void	Harl::error( void ){
	std::cout <<"This is unacceptable! I want to speak to the manager now." <<std::endl;
}

void	Harl::complain(std::string level){
	int	i = 0;

	//Definimos 4 punteros. Cada uno de ellos apunta a una funcion miembro de Harl
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	//Definimos un array de 4 mensajes
    std::string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4)//Pasamos un contador por el array de mensajes
	{
		if (level == msg[i])//Si la string level es igual a una de las cadenas de  mensajes...
		{
			//Ejecutamos el puntero en ese contador (ejecutamos una funcion de las senaladas)
			(this->*ptr[i])();
			break ;
		}
		i++;
	}
}
