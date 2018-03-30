#include "UltimatePlasmaRifle.hpp"

#include <iostream>

UltimatePlasmaRifle::UltimatePlasmaRifle( void ) : UltimatePlasmaRifle::PlasmaRifle() {
	this->_apcost = 20;
	this->_damage = 200;
	std::cout << "Creating Ultimate Plasma Rifle. Ap cost overridden to " << this->_apcost << ". Damage: high."<< std::endl;
}

UltimatePlasmaRifle::UltimatePlasmaRifle( UltimatePlasmaRifle const & ultimatePlasmaRifle ) {
	std::cout << "Copying Ultimate Plasma Rifle." << std::endl;
	*this = ultimatePlasmaRifle;
}

UltimatePlasmaRifle::~UltimatePlasmaRifle( void ) {
	std::cout << "Destroying Ultimate Plasma Rifle." << std::endl;
}

void UltimatePlasmaRifle::attack( void ) const {
	std::cout << "* BOOOZAAAZZZZZZ  *" << std::endl;
}

UltimatePlasmaRifle &    UltimatePlasmaRifle::operator=( UltimatePlasmaRifle const & rhs ) {
	AWeapon::operator=( rhs );
	return (*this);
}