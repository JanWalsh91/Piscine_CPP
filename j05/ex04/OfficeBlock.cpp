#include "OfficeBlock.hpp"
#include "Form.hpp"

#include <iostream>

OfficeBlock::OfficeBlock( void ) : 
	_intern( NULL ), 
	_signer( NULL ), 
	_executor( NULL ) {
	
	return ;
};

OfficeBlock::OfficeBlock( Intern& intern, Bureaucrat& signer, Bureaucrat& executor ) : 
	_intern( &intern ), 
	_signer( &signer ), 
	_executor( &executor ) {

	return ;
};

OfficeBlock::~OfficeBlock( void ) {
	return ;
};

void OfficeBlock::setIntern( Intern& intern ) {
	this->_intern = &intern;
};

void OfficeBlock::setSigner( Bureaucrat& signer ) {
	this->_signer = &signer;
};

void OfficeBlock::setExecutor( Bureaucrat& executor ) {
	this->_executor = &executor;
};

void OfficeBlock::doBureaucracy( std::string formType, std::string target ) {
	if ( !this->_intern ) {
		throw( OfficeBlock::NoInternException() );
	}
	if ( !this->_signer ) {
		throw( OfficeBlock::NoSignerException() );
		return ;
	}
	if ( !this->_executor ) {
		throw( OfficeBlock::NoExecutorException() );
		return ;
	}

	Form* form = this->_intern->makeForm( formType, target );
	this->_signer->signForm( *form );
	this->_executor->executeForm( *form );
	delete form;

};

const char* OfficeBlock::NoInternException::what() const throw() {
	return "Office has no intern";
};
const char* OfficeBlock::NoSignerException::what() const throw() {
	return "Office has no signer";
};
const char* OfficeBlock::NoExecutorException::what() const throw() {
	return "Office has no executor";
};