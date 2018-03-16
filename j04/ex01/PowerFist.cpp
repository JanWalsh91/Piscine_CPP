#include "PowerFist.hpp"

#include <iostream>
#include <string>

PowerFist::PowerFist( void ) : PowerFist::AWeapon( "Power Fist", 8, 50 ) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
};

PowerFist::PowerFist( PowerFist const & powerFist ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = powerFist;
	return ;
};

PowerFist::~PowerFist( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
};

void PowerFist::attack( void ) const {
	std::cout << "* pschhh... SBAM! **" << std::endl;
};