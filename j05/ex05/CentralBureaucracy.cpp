#include "CentralBureaucracy.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>

/* ========== CentralBureaucracy ========== */

CentralBureaucracy::CentralBureaucracy( void ) :_targetList(NULL) {}

CentralBureaucracy::CentralBureaucracy( CentralBureaucracy const & centralBureaucracy ) {
	*this = centralBureaucracy;
}

CentralBureaucracy::~CentralBureaucracy( void ) {
	TargetList *ptr;
	TargetList *tmp;
	ptr = this->_targetList;

	if ( ptr ) {
		while ( ptr->next != NULL ) {
			tmp = ptr;
			ptr = ptr->next;
			delete tmp;
		}
	}
}

CentralBureaucracy &    CentralBureaucracy::operator=( CentralBureaucracy const & rhs ) {
	TargetList *ptr;
	TargetList *ptr2;
	TargetList *tmp;

	ptr = this->_targetList;

	if ( ptr ) {
		while ( ptr->next != NULL ) {
			tmp = ptr;
			ptr = ptr->next;
			delete tmp;
			tmp = NULL;
		}
	}
	this->_targetList = NULL;
	
	ptr = rhs._targetList;
	if ( ptr != NULL ) {
		this->_targetList = ptr;
		ptr2 = this->_targetList;
		while ( ptr->next != NULL ) {
			ptr = ptr->next;
			ptr2 = ptr;
			ptr2 = ptr2->next;
		}
	}
	// *this->_officeBlocks = rhs._officeBlocks; // NO ASSIGNATION FOR OFFICE BLOCKS
	( void )rhs;
	return (*this);
}

void CentralBureaucracy::addBureaucrat( Bureaucrat& bureaucrat ) {
	std::cout << "addBureaucrat " << std::endl;

	for ( int i = 0; i < 20; i++ ) {
		if ( this->_officeBlocks[i].getIntern() == NULL ) {
			Intern joe;
			this->_officeBlocks[i].setIntern( joe );
		}
		if ( this->_officeBlocks[i].getSigner() == NULL ) {
			this->_officeBlocks[i].setSigner( bureaucrat );
			return ;
		}
		else if ( this->_officeBlocks[i].getExecutor() == NULL ) {
			this->_officeBlocks[i].setExecutor( bureaucrat );
			return ;
		}
	}
	throw CentralBureaucracy::BureaucratRejectedException();
}

void CentralBureaucracy::queueUp( std::string target ) {
	std::cout << "queueUp " << target << std::endl;
	TargetList* link = new TargetList;

	link->name = target;
	link->next = NULL;

	TargetList* ptr = this->_targetList;
	if ( ptr == NULL ) {
		this->_targetList = link;
		// std::cout << "first link" << std::endl;
		return ;
	}
	while ( ptr->next ) {
		// std::cout << "looping through links: " << std::endl;
		ptr = ptr->next;
	}
	ptr->next = link;
}

void CentralBureaucracy::doBureaucracy( void ) {
	// std::cout << "doBureaucracy" << std::endl;
	std::srand(std::time(nullptr));
	std::string bitsOfBureaucracy[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	TargetList* ptr = this->_targetList;

	if ( ptr == NULL ) {
		return ;
	}
	int r;
	while ( ptr ) {
		r = std::rand() % 3;
		for ( int i = 0; i < 20; ++i ) {
			try {
				this->_officeBlocks[i].doBureaucracy( bitsOfBureaucracy[r], ptr->name );
			}
			catch (std::exception & e) {
				std::cout << e.what() << std::endl;
			}
		}
		ptr = ptr->next;
	}
}






/* ========== BureaucratRejectedException ========== */

CentralBureaucracy::BureaucratRejectedException::BureaucratRejectedException( void ) {}

CentralBureaucracy::BureaucratRejectedException::BureaucratRejectedException( BureaucratRejectedException const & e ) {
	*this = e;
}

CentralBureaucracy::BureaucratRejectedException::~BureaucratRejectedException( void ) throw() {}

CentralBureaucracy::BureaucratRejectedException &    CentralBureaucracy::BureaucratRejectedException::operator=( CentralBureaucracy::BureaucratRejectedException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* CentralBureaucracy::BureaucratRejectedException::what() const throw() {
	return "Buereaucrat rejected";
}