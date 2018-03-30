#include "Politician.hpp"

#include <iostream>
#include <string>

Politician::Politician( void ) {} ;

Politician::Politician( std::string name ) : Victim(name) {
	std::cout << "Here I am, where are my bribes?" << std::endl;
}

Politician::~Politician( void ) {
	std::cout << "Going to Hell? But I thought bribery was legal! Noooo !!! ...." << std::endl;
}

Politician &    Politician::operator=( Politician const & rhs ) {
	this->_name = rhs._name;
	return (*this);
}

void Politician::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into an orange fly !" << std::endl;
}