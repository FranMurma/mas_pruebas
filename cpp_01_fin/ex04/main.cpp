/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:39:48 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/19 18:51:17 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool parse(std::string s1, std::string s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cout <<"Error. Empty string\n";
		return (false);
	}
	else
		return (true);
}

std::string	replaceMatch(std::string line, std::string s1, std::string s2)
{
	std::string newLine;
	size_t	nextPosition = 0;
	size_t	position = 0;
	while (position != std::string::npos)//Mientras no llegue a final de linea
	{
		nextPosition = line.find(s1, position);//Buscamos la aparicion de s1
		if (nextPosition == std::string::npos)//Si se acaba la linea y no se encuentra s1...
		{
			newLine += line.substr(position);
			break ;
		}
		newLine += line.substr(position, nextPosition - position);//anadimos a newLine la substr entre position y nextPosition
		newLine += s2;//newline = newline+s2. Incrusta s2 en s1.
		position = nextPosition + s1.length();//// Avanzamos a la siguiente posición después de la ocurrencia de 's1' en 'line'.
	}
	return (newLine);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: you have to enter exactly 3 arguments\n";
		std::cerr << "Use: " << argv[0] << " input_file s1 s2" << std::endl;
		return (1);
	}
	if (!parse(argv[2], argv[3]))
		return (-1);
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error opening input file '" << argv[1] << "'" << std::endl;
		return (2);
	}
	std::string outputFile = std::string(argv[1]) + ".replace";
	std::ofstream 	replaced(outputFile);
	if (!replaced.is_open())
	{
		std::cerr << "Error opening output file '" << outputFile << "'" << std::endl;
		return (-1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string	line;
	while (std::getline(file, line))
	{
		std::string replacedLine = replaceMatch(line, s1, s2);
		replaced << replacedLine << std::endl;//toma el resultado de replaceMatch en replacedLine y luego utiliza el operador << para escribir replacedLine en el archivo de salida replaced.
	}
	file.close();
	replaced.close();
	return (0);
}
