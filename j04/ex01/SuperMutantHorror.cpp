#include "SuperMutantHorror.hpp"

#include <iostream>

SuperMutantHorror::SuperMutantHorror( void ) : SuperMutantHorror::SuperMutant() {
	std::cout << "ROOOAAR I EAT BRAINS ! !" << std::endl;
}

SuperMutantHorror::SuperMutantHorror( SuperMutantHorror const & superMutantHorror ) {
	*this = superMutantHorror;
}

SuperMutantHorror::~SuperMutantHorror( void ) {
	std::cout << "Destroying SuperMutantHorror" << std::endl;
}

void SuperMutantHorror::takeDamage( int damage ) {
	if (this->_hp == 0) {
		std::cout << "Super Mutant Horror is already dead ..." << std::endl;
		return ;
	}
	damage -= 10;
	if (damage > 0) {
		this->_hp -= damage;
	}
	else {
		std::cout << "Super Mutant Horror resists the damage!" << std::endl;
	}
	if (this->_hp < 0) {
		this->_hp = 0;
		std::cout << "Aaargh ..." << std::endl;
	}
}

SuperMutantHorror &    SuperMutantHorror::operator=( SuperMutantHorror const & rhs ) {
	Enemy::operator=( rhs );
	return (*this);
}