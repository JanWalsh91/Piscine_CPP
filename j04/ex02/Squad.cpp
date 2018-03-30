#include "Squad.hpp"
#include "ISquad.hpp"

#include <iostream>

/* ============== Squad ============== */

Squad::Squad( void ) : _unitCount(0), _marines(NULL) {
	std::cout << "Default constructor called" << std::endl;
}

// TODO: deep copy
Squad::Squad( Squad const & squad ) : _unitCount(0), _marines(NULL) {
	std::cout << "Copy constructor called" << std::endl;
	*this = squad;
}

// TODO: units inside must be destroyed
Squad::~Squad( void ) {
	std::cout << "Squad destructor called" << std::endl;
	delete this->_marines;
}

// TODO: destroy any units in squad and create new ones
Squad &    Squad::operator=( Squad const & rhs ) {
	std::cout << "Squad assignment called" << std::endl;

	this->_unitCount = rhs._unitCount;

	if ( this->_marines ) {
		delete this->_marines;
	}

	for (int i = 0; i < rhs.getCount(); ++i) {
		ISpaceMarine* a = rhs.getUnit(i);
		this->push(a->clone());
	}

	return (*this);
}

int Squad::getCount( void ) const {
	return (this->_unitCount);
}

ISpaceMarine* Squad::getUnit( int i ) const {
	if ( this->_marines == NULL || i < 0 ) {
		return NULL;
	}
	SpaceMarineNode* head = this->_marines;

	while ( i != 0 ) {
		if ( head->next ) {
			head = head->next;
			--i;
		}
		else {
			break ;
		}
	}
	if ( i == 0 ) {
		return head->marine;
	}
	else {
		return NULL;
	}	
}

int Squad::push( ISpaceMarine* marine ) {
	std::cout << "Pushing to Squad:\t";
	if ( marine == NULL ) {
		return 0;
	}
	if ( this->_marines == NULL ) {
		std::cout << marine << std::endl;
		this->_marines = new SpaceMarineNode(marine);
		this->_unitCount = 1;
		return 1;
	}
	else {
		std::cout << marine << std::endl;
		SpaceMarineNode*	newMarine= new SpaceMarineNode(marine);
		SpaceMarineNode*	head = this->_marines;

		int i = 2;

		while ( head->next != NULL ) {
			++i;
			head = head->next;
		}
		head->next = newMarine;
		this->_unitCount = i;
		return i;
	}
}


/* ============== SpaceMarineNode ============== */

SpaceMarineNode::SpaceMarineNode( void ) {}

SpaceMarineNode::SpaceMarineNode( ISpaceMarine* marine ) :
	marine(marine),
	next(NULL) {

	std::cout << "Node constructor called: " << marine << std::endl;
}

// TODO: deep copy
SpaceMarineNode::SpaceMarineNode( SpaceMarineNode const & spaceMarineNode ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = spaceMarineNode;
}

// TODO: units inside must be destroyed
SpaceMarineNode::~SpaceMarineNode( void ) {
	std::cout << "Node destructor called" << std::endl;
	if (this->next) {
		std::cout << this->next->marine << std::endl;
	}
	if ( this->next ) {
		std::cout << "Destroy next node" << std::endl;
		delete this->next;
	}
	if ( this->marine ) {
		std::cout << "Destroy current marine: " << this->marine << std::endl;
		delete this->marine;
	}
}

SpaceMarineNode &    SpaceMarineNode::operator=( SpaceMarineNode const & rhs ) {
	if ( this->marine ) {
		delete this->marine;
	}

	if ( rhs.marine ) {
		this->marine = rhs.marine->clone();
	}

	return (*this);
}