#include "Squad.hpp"
#include "ISquad.hpp"

#include <iostream>

/* ============== Squad ============== */

Squad::Squad( void ) : _marines(NULL) {
	std::cout << "Default constructor called" << std::endl;
}

Squad::Squad( Squad const & squad ) : _marines(NULL) {
	std::cout << "Copy constructor called" << std::endl;
	*this = squad;
}

Squad::~Squad( void ) {
	std::cout << "Squad destructor called" << std::endl;
	if ( this->_marines ) {
		std::cout << "Destroying marines" << std::endl;
		delete this->_marines;
	}
	this->_marines = NULL;
}

Squad &    Squad::operator=( Squad const & rhs ) {
	std::cout << "Squad assignment called" << std::endl;

	if ( this->_marines ) {
		delete this->_marines;
		this->_marines = NULL;
	}

	for (int i = 0; i < rhs.getCount(); ++i) {
		ISpaceMarine* a = rhs.getUnit(i);
		this->push(a->clone());
	}

	return (*this);
}

int Squad::getCount( void ) const {
	if ( this->_marines == NULL ) {
		return 0;
	}
	int i = 1;
	SpaceMarineNode* head = this->_marines;
	while ( head->next != NULL ) {
		head = head->next;
		++i;
	}
	return i;
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
	if ( marine == NULL ) {
		std::cout << "Must push a marine (like, a real one) !" << std::endl;
		return this->getCount();
	}
	if ( this->_marines == NULL ) {
		// std::cout << marine << "\t";
		
		this->_marines = new SpaceMarineNode(marine);
		return 1;
	}
	else {
		// std::cout << marine << "\t";

		int i = 2;
		SpaceMarineNode*	newMarine= new SpaceMarineNode(marine);
		SpaceMarineNode*	head = this->_marines;

		if ( marine == head->marine ) {
			std::cout << "Marine already in squad !" << std::endl;
			return this->getCount();
		}
		while ( head->next != NULL ) {
			++i;
			head = head->next;
			if ( marine == head->marine ) {
				std::cout << "Marine already in squad !" << std::endl;
				return this->getCount();
			}
		}
		head->next = newMarine;
		return i;
	}
}


/* ============== SpaceMarineNode ============== */

SpaceMarineNode::SpaceMarineNode( void ) {}

SpaceMarineNode::SpaceMarineNode( ISpaceMarine* marine ) :
	marine(marine),
	next(NULL) {

	// std::cout << "Node constructor called: " << marine << "\t";
}

SpaceMarineNode::SpaceMarineNode( SpaceMarineNode const & spaceMarineNode ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = spaceMarineNode;
}

SpaceMarineNode::~SpaceMarineNode( void ) {
	std::cout << "\nNode destructor called\t";
	if ( this->marine ) {
		std::cout << "Delete this marine\t";
		delete this->marine;
		this->marine = NULL;
	}
	if ( this->next ) {
		std::cout << "Destroy next node\t";
		delete this->next;
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