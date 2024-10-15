/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:10:53 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/15 11:17:18 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon      &_weapon;

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack( void );
};

#endif
