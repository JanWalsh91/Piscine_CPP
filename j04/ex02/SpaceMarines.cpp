#include "SpaceMarines.hpp"

#include <iostream>

SpaceMarines::SpaceMarines( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_marine = NULL;
	this->_next = NULL;
	return ;
};

SpaceMarines::SpaceMarines( ISpaceMarine* marine ) {
	std::cout << "Constructor with param called" << std::endl;
	this->_marine = marine;
	this->_next = NULL;
	return ;
};

SpaceMarines::SpaceMarines( SpaceMarines const & spaceMarines ) {
	std::cout << "Copy constructor called" << std::endl;
	const SpaceMarines* ptr = &spaceMarines;
	SpaceMarines* self = this;

	while ( ptr ) {
		self->push( *SpaceMarines(ptr->getUnit(0)) );
		ptr = ptr->_next;
	}
	return ;
};

SpaceMarines::~SpaceMarines( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
};

SpaceMarines &    SpaceMarines::operator=( SpaceMarines const & rhs ) {
	( void )rhs;
	return (*this);
};

int SpaceMarines::getCount( void ) const {
	int i = 0;
	const SpaceMarines* ptr = this;
	if ( ptr == NULL ) {
		return (i);
	}
	++i;
	while ( ptr->_next != NULL ) {
		ptr = ptr->_next;
		++i;
	}
	return (i);
};

ISpaceMarine* SpaceMarines::getUnit( int i ) const {
	const SpaceMarines*	ptr = this;
		
	if ( i >= 0 && ptr != NULL ) {
		while ( ptr->_next != NULL ) {
			ptr = ptr->_next;
		}
	}
	return ptr->_marine;
};

int SpaceMarines::push( ISpaceMarine* marine ) {
	if ( marine == NULL ) {
		return -1;
	}

	int i = 0;
	if ( this->_marine == NULL ) {
		this->_marine = marine;
		this->_next = NULL;
		return i;
	}
	else {
		++i;
		SpaceMarines* ptr = this;
		while ( ptr->_next != NULL ) {
			++i;
			ptr = ptr->_next;
		}
		ptr->_marine = marine;
		ptr->_next = NULL;
		return i;
	}
};