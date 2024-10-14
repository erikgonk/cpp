#ifndef ATTACKS_HPP
# define ATTACKS_HPP

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(const std::string& type);
		Weapon(const Weapon& other);  // Copy constructor
		Weapon& operator=(const Weapon& other);  // Assignment operator
		~Weapon();
		const std::string& getType() const;
		void setType(const std::string& type);
};

class HumanA {
	private:
		std::string name;
		Weapon& weapon;

	public:
		HumanA(const std::string& name, Weapon& weapon);
		HumanA(const HumanA& other); // copy constructor
		HumanA& operator=(const HumanA& other); //assignement operator
		~HumanA();

		const std::string& getName() const;
		void setName(const std::string& name);
		void attack() const;
};

class HumanB {
	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanB(const std::string& name);
		HumanB(const HumanB& other);
		HumanB& operator=(const HumanB& other);
		~HumanB();

		const std::string& getName() const;
		void setName(const std::string& name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif
