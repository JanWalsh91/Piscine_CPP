#include "Victim.hpp"

#include <iostream>
#include <string>

Victim::Victim( void ) {};

Victim::Victim( std::string name ) : _name(name) {
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim( Victim const & victim ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = victim;
}

Victim::~Victim( void ) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

Victim &    Victim::operator=( Victim const & rhs ) {
	this->_name = rhs._name;
	return (*this);
}

std::ostream& operator<<(std::ostream & os, const Victim & victim) {
	os << "I'm " << victim.getName() << " and I like otters !" << std::endl;
    return os;
}

const std::string Victim::getName( void ) const {
	return (this->_name);
}

void Victim::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}