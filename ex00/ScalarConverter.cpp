/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:25:36 by adeestev          #+#    #+#             */
/*   Updated: 2026/10/03 17:53:42 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

enum LiteralType
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	PSEUDO_TYPE,
	INVALID_TYPE
};

static LiteralType detectType(const std::string& input)
{
	if (input.empty())
		return (INVALID_TYPE);

	if (input == "nan" || input == "nanf" ||
		input == "+inf" || input == "+inff" ||
		input == "-inf" || input == "-inff")
		return (PSEUDO_TYPE);
	
	if ((input.length() == 3 && input[0] == '\'' && input[2] == '\'') ||
		(input.length() == 1 && !std::isdigit(input[0])))
		return (CHAR_TYPE);
	
	char *endptr = NULL;
	std::strtod(input.c_str(), &endptr);

	if (*endptr == '\0')
	{
		if (input.find('.') != std::string::npos)
			return (DOUBLE_TYPE);
		return (INT_TYPE);
	}
	
	if (*endptr == 'f' && *(endptr + 1) == '\0')
		return (FLOAT_TYPE);

	return (INVALID_TYPE);
}

static void printPseudoLiteral(const std::string& input)
{
	std::string floatPseudo = input;
	std::string doublePseudo = input;

	if (input == "nanf" || input == "+inff" || input == "-inff")
		doublePseudo = input.substr(0,  input.length() - 1);
	else
		floatPseudo += "f";

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatPseudo << std::endl;
	std::cout << "double: " << doublePseudo << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	LiteralType type = detectType(input);
	
	if (type == INVALID_TYPE)
	{
		std::cout << "Error: invalid input." << std::endl;
		return ;
	}
	if (type == PSEUDO_TYPE)
	{
		printPseudoLiteral(input);
		return ;
	}

	double val = 0.0;
	if (type == CHAR_TYPE)
	{
		char c = (input.length() == 3) ? input[1] : input[0];
		val = static_cast<double>(c);
	}
	else if (type == INT_TYPE)
	{
		long l = std::strtol(input.c_str(), NULL, 10);
		val = static_cast<double>(l);
	}
	else if (type == FLOAT_TYPE)
	{
		float f = static_cast<float>(std::strtod(input.c_str(), NULL));
		val = static_cast<double>(f);
	}
	else
	{
		val = std::strtod(input.c_str(), NULL);
	}

	std::cout << "char: ";
	if (val < 0 || val > 127)
	{
		std::cout << "impossible" << std::endl;
	}
	else if (!std::isprint(static_cast<int>(val)))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
	}

	std::cout << "int: ";
	if (val < INT_MIN || val > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(val) << std::endl;
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << std::endl;
}
