/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:39:48 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/18 20:13:27 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool parse(int argc, std::string s1, std::string s2)
{
	if (argc != 4)
	{
		std::cout <<"Error in arguments number\n";
		return (false);
	}
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
	size_t	position = line.find(s1);// retorna la posicion en que encuentra s1
//	position = line.find(s1, position); // Buscar la siguiente ocurrencia de s1
	while (position != std::string::npos)
	{
		newLine += line.substr(0, position);
		//newLine = la substr de line desde 0 hasta position (que no es s1)
		newLine += s2;//newline = newline+s2. Incrusta s2 en s1.
		position += s1.length();// Position = position (en line) mas el length de s1, corremos la posicion
		line = line.substr(position);// Restringe la línea a partir de la posición actual
		position = 0;  // Reiniciar la posición para buscar la siguiente ocurrencia
	}
	return (newLine);
}

int	main(int argc, char *argv[])
{
	if (!parse(argc, argv[2], argv[3]))
		return (-1);
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error opening input file '" << argv[1] << "'" << std::endl;
		return (-1);
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
