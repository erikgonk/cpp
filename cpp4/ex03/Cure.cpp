/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:07:09 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 18:07:10 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Default constructor called for the materia " << this->_type << std::endl;
}

Cure::Cure(const Cure& copy) {
	*this = copy;
	std::cout << "Copy constructor called for materia " << copy.getType() << std::endl;
}

Cure &Cure::operator=(const Cure& copy) {
	if (this != &copy) {
		this->_type = copy._type;
	}
	std::cout << "Assignement operator called for Materia " << this->_type << std::endl;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure gone bad,.. therefore being incinerated before causing any damage.." << std::endl;
}

AMateria	*Cure::clone(void) const {
	Cure *copy = new Cure();
	return copy;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
