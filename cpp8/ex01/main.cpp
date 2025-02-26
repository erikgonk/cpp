/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:09:24 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 12:21:11 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

typedef typename std::vector<int> int_vec;
void printVector(const int_vec& vec) {
	int_vec tmp;
	std::sort(tmp.begin(), tmp.end());

    for (int_vec::const_iterator it = tmp.begin(); it != tmp.end(); ++it) {
        std::cout << *it << " "; // Print the current element
    }
    std::cout << std::endl; // Add a newline at the end
}

int	main()
{
	try
	{
		Span sp(5);
		sp.addNumber(-6);
		sp.addNumber(5);
		sp.addNumber(17);
		sp.addNumber(89);
		sp.addNumber(11000000);
		printVector(sp);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	{
		std::cout << std::endl;
	}
	try
	{
		Span sp2(2);
		sp2.addNumber(11000000);
		sp2.addNumber(11000001);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
