#include "PlasmaRifle.hpp"

#include <iostream>

PlasmaRifle::PlasmaRifle( void ) : PlasmaRifle::AWeapon( "Plasma Rifle", 5, 21 ) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
};

PlasmaRifle::PlasmaRifle( PlasmaRifle const & plasmaRifle ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = plasmaRifle;
	return ;
};

PlasmaRifle::~PlasmaRifle( void ) {
	// std::cout << "Destructor called" << std::endl;
	return ;
};

void PlasmaRifle::attack( void ) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
};