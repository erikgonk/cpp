#include <iostream>
#include <unistd.h>
#include "attacks.hpp"

int main(void) {
	std::cout << "\033[2J\033[H" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		sleep(1);  
		club.setType("silly, gummy clubs");
		bob.attack();
		sleep(1);  
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		sleep(2);
		jim.setWeapon(club);
		jim.attack();
		sleep(1);  
		club.setType("bananas");
		jim.attack();
	}
	return 0;
}
