/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:32:48 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/10/18 19:28:19 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

    public:
        // CONSTRUCTORS AND DESTRUCTORS
        Point( void );
        Point( Point const & src );
        ~Point( void );

        // CONSTRUCTORS WITH PARAMETERS
        Point( float const x, float const y );
        Point( float const x, float const y, float const aux );
        
        // OPERATOR OVERLOADS
        Point &operator=(const Point &other);

        // GETTERS AND SETTERS
        Fixed getX( void )const;
        Fixed getY( void ) const;

    private:
        Fixed const x;
        Fixed const y;
        Fixed const aux;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
