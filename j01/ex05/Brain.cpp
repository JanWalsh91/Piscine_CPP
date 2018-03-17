#include "Brain.hpp"

#include <iostream>
#include <string>
#include <sstream>

Brain::Brain( void ) {
	return ;
}

Brain::~Brain( void ) {
	return ;
}

std::string Brain::identify( void ) const {
	std::stringstream ss;
	ss << this;
	return ss.str();
}