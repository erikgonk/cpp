/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:07:20 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/22 10:16:01 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Default constructor called for the materia " << this->_type << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy){
	*this = copy;
	std::cout << "Copy constructor called for materia " << copy.getType() << std::endl;
}

Ice &Ice::operator=(const Ice& copy) {
	if (this != &copy) {
		this->_type = copy._type;
	}
	std::cout << "Assignement operator called for Materia " << this->_type << std::endl;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice being melted in a bowl of hot water..." << std::endl;
}

AMateria	*Ice::clone(void) const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
