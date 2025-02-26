/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:50 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 18:11:38 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    system("clear");
	(void)av;
	if (ac != 2)
	{
		std::cout << B_RED << "PLEASE ENTER: <./btc file>" << RESET << std::endl;
		return 1;
	}
	std::cout << std::endl << CYAN << BOLD << ITAL << B_WHI << "💸 Welcome to the Bitcoin exchange 💸" << RESET << std::endl <<  std::endl;


	return 0;
}