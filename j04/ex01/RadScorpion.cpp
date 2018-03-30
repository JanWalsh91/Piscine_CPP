#include "RadScorpion.hpp"

#include <iostream>

RadScorpion::RadScorpion( void ) : RadScorpion::Enemy( 80, "RadScorpion" ){
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion( RadScorpion const & radScorpion ) {
	std::cout << "* click click click *" << std::endl;
	*this = radScorpion;
}

RadScorpion::~RadScorpion( void ) {
	std::cout << "Destroying Rad Scorpion." << std::endl;
}

void RadScorpion::takeDamage( int damage ) {
	if (this->_hp < 0) {
		return ;
	}
	if (damage > 0) {
		this->_hp -= damage;
	}
	if (this->_hp < 0) {
		std::cout << "* SPROTCH *" << std::endl;
	}
}

RadScorpion &    RadScorpion::operator=( RadScorpion const & rhs ) {
	Enemy::operator=( rhs );
	return (*this);
}