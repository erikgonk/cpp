/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:06:27 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 18:10:08 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "Materia default constructor has been called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "Materia constructor has been called with type " << _type << std::endl;
}

AMateria::AMateria(const AMateria& copy) {
	*this = copy;
	std::cout << "Copy constructor called with type " << copy.getType() << std::endl;  
}

AMateria& AMateria::operator=(const AMateria& copy) {
	if (this != &copy) {
		_type = copy._type;
	}
	std::cout << "Assignement operator called for "  << this->_type << std::endl;
	return *this;
}

AMateria::~AMateria(void) {
	std::cout << "The materia " << this->_type << " has been destroyed" << std::endl;
}

const std::string& AMateria::getType(void) const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Used materia " << target.getName() << std::endl;
}
