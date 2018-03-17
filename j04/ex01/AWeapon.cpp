#include "AWeapon.hpp"

#include <iostream>

AWeapon::AWeapon( void ) {
	return ;
};

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : _name(name), _apcost(apcost), _damage(damage) {
	return ;
};

AWeapon::AWeapon( AWeapon const & aWeapon ) {
	*this = aWeapon;
	return ;
};

AWeapon::~AWeapon( void ) {
	return ;
};

std::string AWeapon::getName( void ) const {
	return (this->_name);
};

int AWeapon::getAPCost( void ) const {
	return (this->_apcost);
};

int AWeapon::getDamage( void ) const {
	return (this->_damage);
};

AWeapon &    AWeapon::operator=( AWeapon const & rhs ) {
	this->_name = rhs._name;
	this->_apcost = rhs._apcost;
	this->_damage = rhs._damage;
	return (*this);
};