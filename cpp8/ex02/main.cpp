/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:26:10 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/25 15:04:16 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << *mstack.begin() << std::endl;
	std::cout << mstack.top() << std::endl; 
	mstack.pop();
	std::cout << mstack.size() << std::endl; 
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// std::cout << mstack.rbegin() << std::endl;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	std::stack<int> s(mstack);
	return (0);
}