/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:06:08 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/06 17:48:21 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int> numbers(MAX_VAL);
	int *mirror(new int[MAX_VAL]);
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cout << "didn't save the same value!!" << std::endl;
			return (1);
		}
    }
	try
	{
		numbers[50] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		numbers[-1] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror;
	return (0);
}