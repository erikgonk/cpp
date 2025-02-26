/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:09:22 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 12:08:27 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <limits>
# include <stdexcept>
# include <vector>
# include <algorithm>

typedef typename std::vector<int> int_vec;
typedef typename int_vec::const_iterator const_iterator;

class Span
{
  public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);

	void				addNumber(int N);
	int					shortestSpan(void) const;
	int					longestSpan(void) const;

  private:
	unsigned int		size_;
	int_vec				numbers_;
};

#endif
