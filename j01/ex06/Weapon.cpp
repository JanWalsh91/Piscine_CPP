#include "Weapon.hpp"
#include <string>

Weapon::Weapon( std::string type ) : _type(type) {
	return ;
}

Weapon::~Weapon( void ) {
	return ;
}

std::string const & Weapon::getType( void ) const {
	std::string const & weaponTypeRef = this->_type;
	return weaponTypeRef;
}

void Weapon::setType( std::string type ) {
	this->_type = type;
}