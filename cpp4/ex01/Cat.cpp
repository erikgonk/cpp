/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:03:40 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 19:03:41 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << this->_type << " 🐱 created with default constructor" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	this->_brain = new Brain(*copy._brain);
	std::cout << this->_type  << " 🐱 created with copy constructor" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		this->_type = copy._type;
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	std::cout  << "Cat assignement operator called 🐱" << std::endl;
	return *this;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "😸  Miiaaooo!! 🐈" << std::endl;
}

Brain& Cat::getBrain(void) {
	return *this->_brain;
}

void Cat::setBrain(const Brain& brain) {
	*this->_brain = brain;
}

