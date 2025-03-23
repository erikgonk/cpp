/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:46:30 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/06 18:24:52 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat mario("Mario", 3);
		std::cout << mario << '\n';
		mario.incrementGrade();
		std::cout << mario << '\n';
		mario.decrementGrade();
		mario.decrementGrade();
		std::cout << mario << '\n';
		Bureaucrat luigi("Luigi", 0);
	}
	catch (const std::exception &er)
	{
		std::cout << er.what() << '\n';
	}
	return (0);
}
