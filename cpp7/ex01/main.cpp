/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:58:06 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/22 11:29:41 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T &x)
{
	std::cout << x << " ";
}

void	inc(int &x)
{
	x += 10;
}

int	main(void)
{
	int	tab[5] = {0, 1, 2, 3, 4};

	std::cout << "int array: ";
	iter(tab, 5, print);
	std::cout << "\n";
	iter(tab, 5, inc);
	std::cout << "int array after increment: ";
	iter(tab, 5, print);
	std::cout << "\n";
	std::string arr[5] = {"C++", "is", "a", "crazy", "language"};
	std::cout << "string array: ";
	iter(arr, 5, print);
	std::cout << "\n";
	return (0);
}
