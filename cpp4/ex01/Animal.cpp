/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:02:32 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 19:02:36 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal default constructor called " << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Animal copy constructor called with " << this->_type << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &copy) {
	if (this != &copy) {
		_type = copy._type;
	}
	std::cout << "Assignement operator called for " << this->_type << std::endl;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal deconstructor called on " << this->_type << std::endl;
}

std::string Animal::getType(void) const {
	return this->_type;
}

void Animal::setType(std::string type) {
	this->_type = type;
}

void Animal::makeSound(void) const {
	std::cout << this->_type << " says: " << std::endl;
}
