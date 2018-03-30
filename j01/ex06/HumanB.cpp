#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

HumanB::HumanB( std::string name) : _name(name) {}

HumanB::~HumanB( void ) {}

void HumanB::setWeapon( Weapon & weapon ) {
	this->_weapon = &weapon;
}

void HumanB::attack( void ) const {
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}