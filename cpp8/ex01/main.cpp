/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:09:24 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/06 17:48:21 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	try
	{
		Span sp(5);
		sp.addNumber(-6);
		sp.addNumber(6);
		sp.addNumber(17);
		sp.addNumber(93);
		sp.addNumber(-7);
		sp.printVector();
		std::cout << BOLD << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	{
		std::cout << std::endl;
	}
	try
	{
		Span sp2(3);
		sp2.addNumber(123456789);
		sp2.addNumber(123456799);
		sp2.addNumber(123456699);
		sp2.printVector();
		std::cout << BOLD << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span sp3(5);
		sp3.addRandomNumbers();
		sp3.printVector();
		std::cout << BOLD << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
