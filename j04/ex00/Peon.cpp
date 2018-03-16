#include "Peon.hpp"

#include <iostream>
#include <string>

Peon::Peon( std::string name ) : Victim(name) {
	std::cout << "Zog Zog." << std::endl;
	return ;
};

Peon::~Peon( void ) {
	std::cout << "Bleuark..." << std::endl;
	return ;
};

Peon &    Peon::operator=( Peon const & rhs ) {
	this->_name = rhs._name;
	return (*this);
};

void Peon::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
};