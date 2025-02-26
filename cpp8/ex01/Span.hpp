/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:09:22 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:23 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <limits>
# include <stdexcept>
# include <vector>

# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <algorithm>

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

	void				printVector(void);
	void				addRandomNumbers(void);

  private:
	unsigned int		size_;
	int_vec				numbers_;
};

#endif
