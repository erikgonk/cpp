/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:11:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:04 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->_type = "Dog";
	std::cout << _type << " created with default constructor." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << _type << "  created with copy contructor"  << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
	if  (this != &copy) {
		this->_type = copy._type;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "🐶  Woof,  woof.. 🦮" <<  std::endl;
}

