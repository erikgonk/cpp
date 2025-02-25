/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:37:06 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/25 14:59:02 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <list>
# include <stack>

template <class T> class MutantStack : public std::stack<T>
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
};

#endif