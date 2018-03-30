#include "SuperMutant.hpp"

#include <iostream>

SuperMutant::SuperMutant( void ) : SuperMutant::Enemy( 170, "Super Mutant" ) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const & superMutant ) {
	*this = superMutant;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Destroying SuperMutant" << std::endl;
}

void SuperMutant::takeDamage( int damage ) {
	if (this->_hp == 0) {
		std::cout << "Super Mutant is already dead ..." << std::endl;
		return ;
	}
	damage -= 3;
	if (damage > 0) {
		this->_hp -= damage;
	}
	else {
		std::cout << "Super Mutant resists the damage!" << std::endl;
	}
	if (this->_hp < 0) {
		this->_hp = 0;
		std::cout << "Aaargh ..." << std::endl;
	}
}

SuperMutant &    SuperMutant::operator=( SuperMutant const & rhs ) {
	Enemy::operator=( rhs );
	return (*this);
}