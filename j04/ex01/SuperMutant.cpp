#include "SuperMutant.hpp"

#include <iostream>

SuperMutant::SuperMutant( void ) : SuperMutant::Enemy( 170, "Super Mutant" ) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return ;
};

SuperMutant::SuperMutant( SuperMutant const & superMutant ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = superMutant;
	return ;
};

SuperMutant::~SuperMutant( void ) {
	return ;
};

void SuperMutant::takeDamage( int damage ) {
	if (this->_hp < 0) {
		return ;
	}
	damage -= 3;
	if (damage > 0) {
		this->_hp -= damage;
	}
	if (this->_hp < 0) {
		std::cout << "Aaargh ..." << std::endl;
	}
};