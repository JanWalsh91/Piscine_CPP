#include "AWeapon.hpp"

#include <iostream>

AWeapon::AWeapon( void ) {
	// std::cout << "AWeapon default constructor 1 called" << std::endl;
	return ;
};

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : _name(name), _apcost(apcost), _damage(damage) {
	// std::cout << "AWeapon default constructor called" << std::endl;
	return ;
};

AWeapon::AWeapon( AWeapon const & aWeapon ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = aWeapon;
	return ;
};

AWeapon::~AWeapon( void ) {
	// std::cout << "Destructor called" << std::endl;
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