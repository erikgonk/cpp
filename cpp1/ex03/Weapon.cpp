#include <string>
#include "attacks.hpp"

Weapon::Weapon(const std::string& type) 
	: type(type) {}

Weapon::Weapon(const Weapon& other) {
    this->type = other.type;
}

Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string& type) {
	this->type = type;
}
