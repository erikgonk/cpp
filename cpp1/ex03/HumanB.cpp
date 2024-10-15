#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    this->name = name;
}

HumanB::~HumanB( void )
{
    std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::attack() {
	if (weapon) {
		std::cout << name << " attacks with their " << BOLD << RED << weapon->getType() << RESET << std::endl;
	} else {
		std::cout << "... " << BLUE << this->name << " has no weapon!" << RESET << std::endl;
	};
}

void HumanB::setWeapon( Weapon &weapon )
{
    this->weapon = &weapon;
}
