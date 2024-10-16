/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:36:16 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/16 11:42:46 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <iostream>
# include <string>

class Harl
{
    public:
        Harl( void );
        ~Harl( void );
        void        complain( std::string message );

    private:
        void        debug( void );
        void        info( void );
        void        warning( void );
        void        error( void );
        std::string levels[4];
        void        (Harl::*f[4])( void );
};

#endif
