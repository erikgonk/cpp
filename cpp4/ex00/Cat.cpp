/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:10:41 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 18:10:43 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->_type = "Cat";
	std::cout << this->_type << " created with default constructor" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << this->_type  << " created with copy constructor" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		this->_type = copy._type;
	}
	std::cout  << "Cat assignement operator called" << std::endl;
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "😸  Miiaaooo!! 🐈" << std::endl;
}

