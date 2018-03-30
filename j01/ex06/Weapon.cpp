#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {}

Weapon::~Weapon( void ) {}

std::string const & Weapon::getType( void ) const {
	std::string const & weaponTypeRef = this->_type;
	return weaponTypeRef;
}

void Weapon::setType( std::string type ) {
	this->_type = type;
}