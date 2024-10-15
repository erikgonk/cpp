#include <iostream>
#include <unistd.h>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
	std::cout << "\033[2J\033[H" << std::endl;
	{
		std::cout << BOLD << "round 1" << RESET << std::endl << std::endl;
		sleep(1);
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		usleep(300000);  
		club.setType("silly, gummy clubs");
		bob.attack();
		usleep(300000);  
	}
	{
		for (int i = 0; i < 10; i++) {
			std::cout << "." << std::endl;
			usleep(100000);  
		}
		std::cout << BOLD << "round 2" << RESET << std::endl << std::endl;
		sleep(1);  
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		usleep(300000);  
		jim.setWeapon(club);
		jim.attack();
		usleep(300000);  
		club.setType("bananas");
		jim.attack();
	}
	return 0;
}
