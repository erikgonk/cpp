/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:39:50 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/24 15:50:50 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <vector>

template <typename T> typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
			break ;
	}
	return (it);
}

#endif