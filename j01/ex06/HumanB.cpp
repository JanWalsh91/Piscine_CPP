#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB( std::string name) : name(name) {
	return ;
};

HumanB::~HumanB( void ) {
	return ;
};

void HumanB::setWeapon( Weapon & weapon ) {
	this->weapon = &weapon;
}

void HumanB::attack( void ) {
	std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
};