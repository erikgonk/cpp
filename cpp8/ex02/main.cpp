/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:26:10 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 14:32:15 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
void printMutantStack(const MutantStack<T>& mstack) {
    typename MutantStack<T>::const_iterator it = mstack.begin();
    typename MutantStack<T>::const_iterator ite = mstack.end();
	
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
	std::cout << std::endl;
}

template <typename T>
void revPrintMutantStack(const MutantStack<T>& mstack) {
    typename MutantStack<T>::const_reverse_iterator it = mstack.rbegin();
    typename MutantStack<T>::const_reverse_iterator ite = mstack.rend();
	
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
	std::cout << std::endl;
}

template <typename T>
template <typename Iterator>
void MutantStack<T>::PrintIt(Iterator it, Iterator ite) {
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
	std::cout << std::endl;
}

template <typename T>
void MutantStack<T>::addRandomNumbersToStack(size_t size) {
    unsigned int seed = static_cast<unsigned int>(time(0)) ^ getpid();
    srand(seed);

    for (size_t i = 0; i < size; ++i) {
        T randomNumber = rand() % 100;
        this->push(randomNumber);
    }
}

template <typename T>
void MutantStack<T>::myTests(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "--------------------------------------" << std::endl;
	mstack.PrintIt(mstack.begin(), mstack.end());
	std::cout << "--------------------------------------" << std::endl;
	mstack.PrintIt(mstack.rbegin(), mstack.rend());
	mstack.pop();
	std::cout << "--------------------------------------" << std::endl;
	printMutantStack(mstack);
	std::stack<int> s(mstack);
	std::cout << "--------------------------------------" << std::endl;
	MutantStack<int> mstack2;
	mstack2.addRandomNumbersToStack(10);
	printMutantStack(mstack2);
}

template <typename T>

void MutantStack<T>::mainTests(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int	main(void)
{
	MutantStack<int> main;
	main.mainTests();
	MutantStack<int> erik;
	erik.myTests();
	return (0);
}