/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:45:20 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/12 16:37:19 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat mario("Mario", 3);
		Form contract("Contract", 70, 1);
		std::cout << mario << '\n';
		std::cout << contract << '\n';
		mario.signForm(contract);
		std::cout << contract << '\n';
		Bureaucrat luigi("Luigi", 61);
		// Form contract("Contract", 5, 1);
		luigi.signForm(contract);
	}
	catch (const std::exception &er)
	{
		std::cerr << er.what() << '\n';
	}
	return (0);
}
