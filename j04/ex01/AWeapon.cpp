#include "AWeapon.hpp"

#include <iostream>

AWeapon::AWeapon( void ) {}

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : _name(name), _apcost(apcost), _damage(damage) {
	std::cout << "Creating weapon: " << this->_name
		<< ". AP cost: " << this->getAPCost()
		<< ". Damage: " << this->getDamage()
		<< std::endl;
}

AWeapon::AWeapon( AWeapon const & aWeapon ) {
	*this = aWeapon;
	std::cout << "Copying weapon: " << this->_name << std::endl;
}

AWeapon::~AWeapon( void ) {
	std::cout << "Destoying weapon: " << this->_name << std::endl;
}

std::string const AWeapon::getName( void ) const {
	return (this->_name);
}

int AWeapon::getAPCost( void ) const {
	return (this->_apcost);
}

int AWeapon::getDamage( void ) const {
	return (this->_damage);
}

AWeapon &    AWeapon::operator=( AWeapon const & rhs ) {
	this->_name = rhs._name;
	this->_apcost = rhs._apcost;
	this->_damage = rhs._damage;
	return (*this);
}