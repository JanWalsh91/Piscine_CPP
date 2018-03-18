#include "Sorcerer.hpp"
#include "Victim.hpp"

#include <iostream>
#include <string>

Sorcerer::Sorcerer( std::string name, std::string title ) : _name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return ;
};

Sorcerer::Sorcerer( Sorcerer const & sorcerer ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = sorcerer;
	return ;
};

Sorcerer::~Sorcerer( void ) {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
	return ;
};

Sorcerer &    Sorcerer::operator=( Sorcerer const & rhs ) {
	this->_name = rhs._name;
	this->_title = rhs._title;
	return (*this);
};

std::ostream& operator<<( std::ostream& os, const Sorcerer & sorcerer )
{
	os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !";
    return os;
}

std::string Sorcerer::getName( void ) const {
	return (this->_name);
};

std::string Sorcerer::getTitle( void ) const {
	return (this->_title);
};

void Sorcerer::polymorph( Victim const & victim ) const {
	victim.getPolymorphed();
};