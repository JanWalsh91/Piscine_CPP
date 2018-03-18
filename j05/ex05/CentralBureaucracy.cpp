#include "CentralBureaucracy.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>

CentralBureaucracy::CentralBureaucracy( void ) {
	// std::cout << "Default constructor called" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		this->_officeBlocks[i] = new OfficeBlock();
	}
	this->_targetList = NULL;
	return ;
};

CentralBureaucracy::CentralBureaucracy( CentralBureaucracy const & centralBureaucracy ) {
	// std::cout << "Copy constructor called" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		this->_officeBlocks[i] = new OfficeBlock(*centralBureaucracy.getOfficeBlock(i));
	}
	this->_targetList = NULL;
	*this = centralBureaucracy;
	return ;
};

CentralBureaucracy::~CentralBureaucracy( void ) {
	// std::cout << "Destructor called" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		delete this->_officeBlocks[i];
	}
	return ;
};

CentralBureaucracy &    CentralBureaucracy::operator=( CentralBureaucracy const & rhs ) {
	for ( int i = 0; i < 20; i++ ) {
		this->_officeBlocks[i] = new OfficeBlock(*rhs.getOfficeBlock(i));
	}
	return (*this);
};

const OfficeBlock* CentralBureaucracy::getOfficeBlock( int i ) const {
	if ( i < 0 || i > 20 ) {
		throw std::out_of_range("Central Bureaucracy only has 20 office blocks.");
	}
	return ( this->_officeBlocks[i] );
};

void CentralBureaucracy::addBureaucrat( Bureaucrat& bureaucrat ) {
	OfficeBlock* officeBlock = NULL;

	for ( int i = 0; i < 20; i++ ) {
		officeBlock = _officeBlocks[i];
		if ( officeBlock->getIntern() == NULL ) {
			Intern joe;
			officeBlock->setIntern( joe );
		}
		if ( officeBlock->getSigner() == NULL ) {
			officeBlock->setSigner( bureaucrat );
			return ;
		}
		else if ( officeBlock->getExecutor() == NULL ) {
			officeBlock->setExecutor( bureaucrat );
			return ;
		}
	}
};

void CentralBureaucracy::queueUp( std::string target ) {
	// std::cout << "queueUp " << target << std::endl;
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
};

void CentralBureaucracy::doBureaucracy( void ) {
	// std::cout << "doBureaucracy" << std::endl;
	std::srand(std::time(nullptr));
	std::string bitsOfBureaucracy[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	TargetList* ptr = this->_targetList;

	if ( ptr == NULL ) {
		// std::cout << "no targets" << std::endl;
		return ;
	}
	int r;
	int i = 0;
	while ( ptr ) {
		// std::cout << "doBureaucracy round" << std::endl;
		r = std::rand() % 3;
		try {
			this->_officeBlocks[i]->doBureaucracy( bitsOfBureaucracy[r], ptr->name );
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		ptr = ptr->next;
		++i;
	}
};

const char* CentralBureaucracy::BureaucratRejectedException::what() const throw() {
	return "Buereaucrat rejected";
};
