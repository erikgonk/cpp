/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Olifant.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:11:21 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 19:08:31 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Olifant.hpp"

Olifant::Olifant(void) {
	this->_type = "Olifant";
	std::cout << this->_type << " 🐘 created with default constructor" << std::endl;
}

Olifant::Olifant(const Olifant& copy) : WrongAnimal(copy) {
	std::cout << this->_type  << " 🐘 created with copy constructor" << std::endl;
	*this = copy;
}

Olifant& Olifant::operator=(const Olifant& copy) {
	if (this != &copy) {
		this->_type = copy._type;
	}
	std::cout  << "Olifant 🐘 assignement operator called" << std::endl;
	return *this;
}

Olifant::~Olifant(void) {
	std::cout << "Olifant deconstructor called  🐘" << std::endl;
}

void Olifant::makeSound(void) const {
	std::cout << " 🐧 Miiaaooo!! 🐘" << std::endl;
}
