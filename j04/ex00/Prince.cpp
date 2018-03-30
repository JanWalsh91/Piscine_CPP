#include "Prince.hpp"

#include <iostream>
#include <string>

Prince::Prince( void ) {} ;

Prince::Prince( std::string name ) : Noble(name) {
	std::cout << "I am a young and valiant prince." << std::endl;
}

Prince::~Prince( void ) {
	std::cout << "I have died, and I haven't found my princess." << std::endl;
}

Prince &    Prince::operator=( Prince const & rhs ) {
	this->_name = rhs._name;
	return (*this);
}

void Prince::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into a yellow oyster !" << std::endl;
}