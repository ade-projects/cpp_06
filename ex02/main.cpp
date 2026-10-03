/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:16:24 by adeestev          #+#    #+#             */
/*   Updated: 2026/10/03 17:54:22 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << " - Testing random generation -\n" << std::endl;
	for (int i = 1; i < 10; i++)
	{
		std::cout << "Test number " << i << ":" << std::endl;
		Base* instance = generate();

		std::cout << "Identify by pointer: "; 
		identify(instance);

		std::cout << "Identify by reference: ";
		identify(*instance);
	
		delete instance;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << " - Testing objects -\n" << std::endl;
	A a;
	B b;
	C c;

	std::cout << "A object -> pointer: ";
	identify(&a);
	std::cout << "A object -> reference: ";
	identify(a);

	std::cout << "B object -> pointer: ";
	identify(&b);
	std::cout << "B object -> reference: ";
	identify(b);

	std::cout << "C object -> pointer: ";
	identify(&c);
	std::cout << "C object -> reference: ";
	identify(c);

	std::cout << std::endl;

	return (0);
}
