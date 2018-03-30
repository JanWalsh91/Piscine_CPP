#include "PowerFist.hpp"

#include <iostream>
#include <string>

PowerFist::PowerFist( void ) : PowerFist::AWeapon( "Power Fist", 8, 50 ) {
	std::cout << "Creating Power Fist." << std::endl;
}

PowerFist::PowerFist( PowerFist const & powerFist ) {
	std::cout << "Copying Power Fist." << std::endl;
	*this = powerFist;
}

PowerFist::~PowerFist( void ) {
	std::cout << "Destroying Power Fist." << std::endl;
}

void PowerFist::attack( void ) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &    PowerFist::operator=( PowerFist const & rhs ) {
	AWeapon::operator=( rhs );
	return (*this);
}