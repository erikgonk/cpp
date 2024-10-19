/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:25 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/19 12:01:27 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed( void );
        Fixed( const Fixed & src );
        ~Fixed( void );
        Fixed & operator=( const Fixed & rhs );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif
