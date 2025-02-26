/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:21:49 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/26 12:15:58 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : size_(N)
{
	numbers_.reserve(N);
}

Span::Span(const Span &other)
{
	size_ = other.size_;
	numbers_ = other.numbers_;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	size_ = other.size_;
	numbers_ = other.numbers_;
	return (*this);
}

Span::~Span(void)
{
}

void Span::addNumber(int number)
{
	if (numbers_.size() >= size_)
		throw std::out_of_range("Span is full");
	numbers_.push_back(number);
}

int Span::shortestSpan(void) const {
    if (numbers_.size() < 2) {
        throw std::out_of_range("Span is too short");
    }

    int_vec sorted(numbers_);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();

    for (const_iterator it = sorted.begin(); it != sorted.end() - 1; ++it) {
        minSpan = std::min(minSpan, *(it + 1) - *it);
    }

    return minSpan;
}

int Span::longestSpan(void) const
{
	if (numbers_.size() < 2)
		throw std::out_of_range("Span is too short");
	int_vec sorted(numbers_);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[size_ - 1] - sorted[0]);
}
