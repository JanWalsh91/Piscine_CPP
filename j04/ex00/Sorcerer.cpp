#include "Sorcerer.hpp"
#include "Victim.hpp"

#include <iostream>
#include <string>

Sorcerer::Sorcerer( void ) {} ;

Sorcerer::Sorcerer( std::string name, std::string title ) : _name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const & sorcerer ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = sorcerer;
}

Sorcerer::~Sorcerer( void ) {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &    Sorcerer::operator=( Sorcerer const & rhs ) {
	this->_name = rhs._name;
	this->_title = rhs._title;
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Sorcerer & sorcerer )
{
	os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
    return os;
}

const std::string Sorcerer::getName( void ) const {
	return (this->_name);
}

const std::string Sorcerer::getTitle( void ) const {
	return (this->_title);
}

void Sorcerer::polymorph( Victim const & victim ) const {
	victim.getPolymorphed();
}