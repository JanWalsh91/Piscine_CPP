#include "Brain.hpp"

#include <iostream>
#include <sstream>

Brain::Brain( int brainPower  ) : _brainPower( brainPower ) {
	std::cout<< "Created brain with brainpower " << this->_brainPower << std::endl;
}

Brain::~Brain( void ) {}

std::string Brain::identify( void ) const {
	std::stringstream ss;
	ss << this;
	return ss.str();
}