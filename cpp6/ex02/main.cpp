/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:46:30 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/19 16:13:11 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


Base	*generate(void)
{
	std::time_t current(std::time(0));
	int random(current % 3);
	switch (random)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		return (0);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void	identify(Base &p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(&p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(&p))
		std::cout << "C\n";
}

int	main(void)
{
	Base *base(generate());
	std::cout << "Identify using pointer: ";
	identify(base);
	std::cout << "Identify using reference: ";
	identify(*base);
	delete (base);
	return (0);
}