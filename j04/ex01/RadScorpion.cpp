#include "RadScorpion.hpp"

#include <iostream>

RadScorpion::RadScorpion( void ) : RadScorpion::Enemy( 80, "RadScorpion" ){
	std::cout << "* click click click *" << std::endl;
	return ;
};

RadScorpion::RadScorpion( RadScorpion const & radScorpion ) {
	*this = radScorpion;
	return ;
};

RadScorpion::~RadScorpion( void ) {
	return ;
};

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
};