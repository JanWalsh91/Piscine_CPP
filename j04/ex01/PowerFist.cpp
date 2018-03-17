#include "PowerFist.hpp"

#include <iostream>
#include <string>

PowerFist::PowerFist( void ) : PowerFist::AWeapon( "Power Fist", 8, 50 ) {
	return ;
};

PowerFist::PowerFist( PowerFist const & powerFist ) {
	*this = powerFist;
	return ;
};

PowerFist::~PowerFist( void ) {
	return ;
};

void PowerFist::attack( void ) const {
	std::cout << "* pschhh... SBAM! **" << std::endl;
};