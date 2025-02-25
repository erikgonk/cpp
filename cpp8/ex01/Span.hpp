/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:09:22 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/25 13:19:25 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <vector>

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
	std::vector<int>	numbers_;
};

#endif