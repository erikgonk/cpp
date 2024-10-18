#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed( void );
        Fixed( const Fixed & src );
        ~Fixed( void );
        Fixed( int const value );

        Fixed & operator=( const Fixed & rhs );
        Fixed( float const value );

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
