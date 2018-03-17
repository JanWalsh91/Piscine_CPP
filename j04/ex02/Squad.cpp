#include "Squad.hpp"
#include "ISquad.hpp"

#include <iostream>

Squad::Squad( void ) : _unitCount(0), _marines(NULL) {
	std::cout << "Default constructor called" << std::endl;
	return ;
};

// TODO: deep copy
Squad::Squad( Squad const & squad ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = squad;
	return ;
};

// TODO: units inside must be destroyed
Squad::~Squad( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
};

// TODO: destroy any units in squad and create new ones
Squad &    Squad::operator=( Squad const & rhs ) {
	this->_unitCount = rhs._unitCount;

	return (*this);
};

int Squad::getCount( void ) const {
	return (this->_unitCount);
};

ISpaceMarine* Squad::getUnit( int i ) const {
	return this->_marines->getUnit( i );	
};

int Squad::push( ISpaceMarine* marine ) {
	if ( marine == NULL ) {
		return -1;
	}
	++(this->_unitCount);
	return this->_marines->push( marine );
};
