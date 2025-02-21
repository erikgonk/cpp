/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:46:30 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/19 12:26:27 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.id = 42;
	data.name = "erigonza";
	std::cout << "Data &: " << &data << "\n";
	raw = Serializer::serialize(&data);
	std::cout << "RAW &: " << &raw << "\n";
	ptr = Serializer::deserialize(raw);
	std::cout << "PTR &: " << &ptr << "\n";
	if (ptr == &data)
	{
		std::cout << "Data ID: " << ptr->id << "\n";
		std::cout << "Data Name: " << ptr->name << "\n";
	}
	return (0);
}
