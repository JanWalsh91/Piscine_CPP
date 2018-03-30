#include "PlasmaRifle.hpp"

#include <iostream>

PlasmaRifle::PlasmaRifle( void ) : PlasmaRifle::AWeapon( "Plasma Rifle", 5, 21 ) {
	std::cout << "Creating Plasma Rifle." << std::endl;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & plasmaRifle ) {
	std::cout << "Copying Plasma Rifle." << std::endl;
	*this = plasmaRifle;
}

PlasmaRifle::~PlasmaRifle( void ) {
	std::cout << "Destroying Plasma Rifle." << std::endl;
}

void PlasmaRifle::attack( void ) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle &    PlasmaRifle::operator=( PlasmaRifle const & rhs ) {
	AWeapon::operator=( rhs );
	return (*this);
}