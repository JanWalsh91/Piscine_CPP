#include "PlasmaRifle.hpp"

#include <iostream>

PlasmaRifle::PlasmaRifle( void ) : PlasmaRifle::AWeapon( "Plasma Rifle", 5, 21 ) {
	return ;
};

PlasmaRifle::PlasmaRifle( PlasmaRifle const & plasmaRifle ) {
	*this = plasmaRifle;
	return ;
};

PlasmaRifle::~PlasmaRifle( void ) {
	return ;
};

void PlasmaRifle::attack( void ) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
};