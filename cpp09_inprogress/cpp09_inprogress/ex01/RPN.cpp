/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:58:00 by frmurcia          #+#    #+#             */
/*   Updated: 2024/04/03 20:31:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

# include "RPN.hpp"

bool isSpace(char a, char b) {
	return (a == ' ' && b == ' ');
}

std::string normalizeInput(const std::string& input) {
	std::string normalized = input;
	// Eliminar espacios duplicados
	std::string::iterator last = std::unique(normalized.begin(), normalized.end(), isSpace);
	//std::unique tiene un iterador, que recorre el rango de inicio a fin, y busca lo que consideramos 'elementos iguales'(isSpace).
	normalized.erase(last, normalized.end());
	return (normalized);
}

bool	RPNCalculator::isInteger(const std::string& str) const {//Vamos a recibir los tokens y comprobar si son digitos de -9 a 9
	if (str.empty())
		return (false); // La cadena está vacía
	// Comprobamos si el primer carácter es un signo negativo o un dígito
	size_t	start = 0;
	if (str[start] == '-')
		start = 1; // Saltamos el signo negativo
	if (!std::isdigit(str[start]) || (str[start + 1] && (str[start + 1] != ' '))) {
		return (false); // Carácter no es un dígito
	}
	return (true); // Todos los caracteres son dígitos
}

int	RPNCalculator::evaluateExpression(const std::string& expression) const {
	std::string normalizedExpression = normalizeInput(expression);//Usamos en lugar de la string original una copia que coge dobles espacios
	std::istringstream	iss(normalizedExpression);
	std::stack<int>		operandsStack;
	std::string			token;
	bool				flag = false;
	while (std::getline(iss, token, ' ')) {// Separamos la string de entrada, recogidas en un objeto istringstream, en tokens separados por espacios
		if (isInteger(token)) {//Si lo que encontramos es un digito 0-9
			operandsStack.push(convertToInt(token));//lo convertimos a un int (era un char) y lo agregamos al operandsStack (stack de ints)
		}
		else {
			if (operandsStack.size() < 2) {//Si al acabar de tokenizar tenemos menos de 2 operandos, expresion invalida
				throw std::runtime_error("invalid expression");
			}
			//// Si el token no es un dígito (operando), asumimos que es un operador
			int	operand2 = operandsStack.top();//Creamos un int operand2, copiamos el primer elemento de operandsStack
			operandsStack.pop();//Eliminamos el int copiado.
			int operand1 = operandsStack.top();// Copiamos en operand1 el que ahora es primer (y antes segundo) elemento
			operandsStack.pop();//Eliminamos el primer elemento otra vez, los tenemos ya colocados.
			
			if (token == "+")
				operandsStack.push(operand1 + operand2);
			else if (token == "-")
				operandsStack.push(operand1 - operand2);
			else if (token == "*")
				operandsStack.push(operand1 * operand2);
			else if (token == "/") {
				if (operand2 == 0)
					throw std::runtime_error("division by zero");
				operandsStack.push(operand1 / operand2);
				}
			else
				throw std::runtime_error("unknown operator");
			flag = true;
			}
		}
	if (flag == false) {
		std::cout << "Operadores vacio\n";
		throw std::runtime_error("invalid expression");
	}
	if (operandsStack.size() != 1) {
		throw std::runtime_error("invalid expression");
	}
	return (operandsStack.top());
}

int	RPNCalculator::convertToInt(const std::string& str) const {
	std::istringstream iss(str);
	int result;
	iss >> result;
	return (result);
}

/*********
Un iterador de std::stack proporciona acceso secuencial a los elementos almacenados en la pila. 
Sin embargo, es importante destacar que la pila no proporciona un iterador público en el estándar C++. 
Esto se debe a que la interfaz de std::stack se basa en la pila subyacente que está encapsulada 
(por ejemplo, std::deque, std::list, std::vector, etc.), y no todas estas estructuras de datos proporcionan un iterador público.

Por lo tanto, si necesitas acceder a los elementos de la pila de manera secuencial, 
puedes hacerlo sacando elementos uno a uno con pop() hasta que la pila esté vacía, 
o puedes usar una estructura de datos diferente que sí admita iteración, 
como std::vector o std::deque, y luego usar un bucle para iterar sobre ellos.
El contenedor stack es LIFO, por tanto es el más adecuado para este ejercicio porque refleja el comportamiento natural de cómo se procesan 
y manipulan los elementos en la evaluación de expresiones en notación polaca inversa. 
Proporciona un enfoque simple y eficiente para realizar el cálculo requerido.

******************/
