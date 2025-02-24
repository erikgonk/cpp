/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:21:49 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/24 16:30:59 by erigonza         ###   ########.fr       */
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

template <class It> void Span::addNumber(It begin, It end)
{
	if (numbers_.size() + std::distance(begin, end) > size_)
		throw std::out_of_range("Span is full");
	numbers_.insert(numbers_.end(), begin, end);
}

int Span::shortestSpan(void) const
{
	if (numbers_.size() < 2)
		throw std::out_of_range("Span is too short");
	std::vector<int> sorted(numbers_);
	std::sort(sorted.begin(), sorted.end());
	int min(sorted[1] - sorted[0]);
	for (size_t i = 1; i < size_; i++)
	{
		int span(sorted[i] - sorted[i - 1]);
		if (span < min)
			min = span;
	}
	return (min);
}

int Span::longestSpan(void) const
{
	if (numbers_.size() < 2)
		throw std::out_of_range("Span is too short");
	std::vector<int> sorted(numbers_);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[size_ - 1] - sorted[0]);
}