#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA( std::string _name, Weapon &weapon ) : _name(_name), _weapon(weapon) {}

HumanA::~HumanA( void )
{
    std::cout << "HumanA destructor called" << std::endl;
}

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << BOLD_RED << this->_weapon.getType() << RESET << std::endl;
}
