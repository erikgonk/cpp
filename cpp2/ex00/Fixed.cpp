/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:20 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/19 12:01:24 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
    return ;
}

// Copy constructor
Fixed::Fixed( const Fixed & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Destructor
Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

// Copy assignment operator
Fixed & Fixed::operator=( const Fixed & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if ( this != &rhs ) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
    return ;
}
