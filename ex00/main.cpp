/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:16:24 by adeestev          #+#    #+#             */
/*   Updated: 2026/10/03 17:53:36 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);

	return (0);
}
