/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:16:24 by adeestev          #+#    #+#             */
/*   Updated: 2026/10/03 17:53:54 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data originalData;
	originalData.name = "Project's date";
	originalData.type = "object";
	originalData.id = 42;
	originalData.value = 09.2026;

	std::cout << std::endl;
	std::cout << " - Before serialization: -\n" << std::endl;
	std::cout << "Original pointer address: " << &originalData << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Type: " << originalData.type << std::endl;
	std::cout << "Id: " << originalData.id << std::endl;
	std::cout << "Value: " << originalData.value << std::endl;
	std::cout << std::endl;


	std::cout << " - During serialization: -\n" << std::endl;
	uintptr_t rawBits = Serializer::serialize(&originalData);
	std::cout << "Serialized uintptr_t (Raw integer address): " << rawBits
		<< " (Hex: 0x" << std::hex << rawBits << std::dec << ")" << std::endl;
	std::cout << std::endl;
	
	Data* deserializedData = Serializer::deserialize(rawBits);

	std::cout << " - After deserialization: -\n" << std::endl;
	std::cout << "Deserialized pointer address: " << deserializedData << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;
	std::cout << "Type: " << deserializedData->type << std::endl;
	std::cout << "Id: " << deserializedData->id << std::endl;
	std::cout << "Value: " << deserializedData->value << std::endl;
	std::cout << std::endl;

	if (deserializedData == &originalData)
	{
		std::cout << "Deserialized pointer matches the original one." << std::endl;
	}
	else
	{
		std::cout << "Deserialized pointer doesn't match the original one." << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
