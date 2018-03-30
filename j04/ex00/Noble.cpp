#include "Noble.hpp"

#include <iostream>
#include <string>

Noble::Noble( void ) {} ;

Noble::Noble( std::string name ) : Victim(name) {
	std::cout << "I am alive ... and rich!" << std::endl;
}

Noble::~Noble( void ) {
	std::cout << "I die ... and so does my money ..." << std::endl;
}

Noble &    Noble::operator=( Noble const & rhs ) {
	this->_name = rhs._name;
	return (*this);
}

void Noble::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into a green monkey !" << std::endl;
}