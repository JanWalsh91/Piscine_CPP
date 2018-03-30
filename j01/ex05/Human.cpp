#include "Human.hpp"
#include <iostream>

Human::Human( void ): _brain( Brain(50) ) {}

Human::~Human( void ) {}

std::string Human::identify( void ) const {
	return this->_brain.identify();
}

Brain const & Human::getBrain( void ) const {
	Brain const & brainRef = this->_brain;
	return brainRef;
}
