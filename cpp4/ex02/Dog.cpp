/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:28:11 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 17:28:13 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << _type << " 🐶 created with default constructor." << std::endl;
}

Dog::Dog(const Dog& copy) : AAnimal(copy) {
	this->_brain = new Brain(*copy._brain);
	std::cout << _type << " 🐶 created with copy contructor"  << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
	if  (this != &copy) {
		this->_type = copy._type;
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	std::cout << "Dog assignment operator called 🐶" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog deconstructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "🐶  Woof,  woof.. 🦮" <<  std::endl;
}

Brain& Dog::getBrain(void) {
	return *this->_brain;
}

void Dog::setBrain(const Brain& brain) {
	*this->_brain = brain;
}
