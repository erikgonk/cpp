/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:50 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/27 10:06:12 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
    system("clear");
	if (ac != 2)
	{
		std::cout << B_RED << "PLEASE ENTER: <./btc file>" << RESET << std::endl;
		return 1;
	}
	std::cout << std::endl << CYAN << BOLD << ITAL << B_WHI << "💸 Welcome to the Bitcoin exchange 💸" << RESET << std::endl <<  std::endl;
	try {
		std::cout << BOLD_RED << B_YLW << "** Money makes the World go around **" << RESET << std::endl <<std::endl;
		BitcoinExchange btc;
		btc.execute(av[1]);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
