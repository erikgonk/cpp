/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:37:06 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 17:14:49 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <list>
# include <stack>

# include <unistd.h>
# include <cstdlib>
# include <ctime>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template <class T>
class MutantStack : public std::stack<T>
{
  public:
	MutantStack(void)
	{
	}
	MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
	{
	}
	MutantStack<T> &operator=(const MutantStack<T> &other)
	{
		if (this == &other)
			return (*this);
		std::stack<T>::operator=(other);
		return (*this);
	}
	~MutantStack(void)
	{
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(void)
	{
		return (std::stack<T>::c.begin());
	}
	iterator end(void)
	{
		return (std::stack<T>::c.end());
	}

	const_iterator begin(void) const
	{
		return (std::stack<T>::c.begin());
	}
	const_iterator end(void) const
	{
		return (std::stack<T>::c.end());
	}

	reverse_iterator rbegin(void)
	{
		return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend(void)
	{
		return (std::stack<T>::c.rend());
	}

	const_reverse_iterator rbegin(void) const
	{
		return (std::stack<T>::c.rbegin());
	}
	const_reverse_iterator rend(void) const
	{
		return (std::stack<T>::c.rend());
	}
	
	void	addRandomNumbersToStack(size_t size);
	void	myTests(void);
	void	mainTests(void);
	
	template <typename Iterator> void PrintIt(Iterator it, Iterator ite);
};

#endif