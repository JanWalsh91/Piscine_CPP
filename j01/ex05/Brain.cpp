#include <iostream>
#include <string>
#include <sstream>
#include "Brain.hpp"

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