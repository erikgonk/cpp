/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:07:40 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/24 13:35:14 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <iostream>
# include <stdexcept>

#define MAX_VAL 750

template <typename T> class Array
{
  public:
	Array(void) : size_(0), data_(NULL) {}
	Array(unsigned int n) : size_(n), data_(new T[n]){}
	Array(const Array &other) : size_(other.size_)
	{
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			data_[i] = other.data_[i];
	}
	Array &operator=(const Array &other)
	{
		if (this == &other)
			return (*this);
		delete[] data_;
		size_ = other.size_;
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			data_[i] = other.data_[i];
		return (*this);
	}
	~Array(void)
	{
		delete[] data_;
	}
	T &operator[](unsigned int index)
	{
		if (index >= size_)
			throw std::out_of_range("Index out of range");
		return (data_[index]);
	}
	const T &operator[](unsigned int index) const
	{
		if (index >= size_)
			throw std::out_of_range("Index out of range");
		return (data_[index]);
	}
	unsigned int size() const
	{
		return (size_);
	}

  private:
	unsigned int size_;
	T *data_;
};

#endif
