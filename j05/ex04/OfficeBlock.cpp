#include "OfficeBlock.hpp"
#include "Form.hpp"

/* ========== OfficeBlock ========== */

OfficeBlock::OfficeBlock( void ) : 
	_intern( NULL ), 
	_signer( NULL ), 
	_executor( NULL ) {
}

OfficeBlock::OfficeBlock( Intern& intern, Bureaucrat& signer, Bureaucrat& executor ) : 
	_intern( &intern ), 
	_signer( &signer ), 
	_executor( &executor ) {
}

OfficeBlock::~OfficeBlock( void ) {}

void OfficeBlock::setIntern( Intern& intern ) {
	this->_intern = &intern;
}

void OfficeBlock::setSigner( Bureaucrat& signer ) {
	this->_signer = &signer;
}

void OfficeBlock::setExecutor( Bureaucrat& executor ) {
	this->_executor = &executor;
}

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

}

/* ========== NoInternException ========== */

OfficeBlock::NoInternException::NoInternException( void ) {}

OfficeBlock::NoInternException::NoInternException( OfficeBlock::NoInternException const & e ) {
	*this = e;
}

OfficeBlock::NoInternException::~NoInternException( void ) throw() {}

OfficeBlock::NoInternException &    OfficeBlock::NoInternException::operator=( OfficeBlock::NoInternException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* OfficeBlock::NoInternException::what() const throw() {
	return "Office has no intern";
}

/* ========== NoSignerException ========== */

OfficeBlock::NoSignerException::NoSignerException( void ) {}

OfficeBlock::NoSignerException::NoSignerException( OfficeBlock::NoSignerException const & e ) {
	*this = e;
}

OfficeBlock::NoSignerException::~NoSignerException( void ) throw() {}

OfficeBlock::NoSignerException &    OfficeBlock::NoSignerException::operator=( OfficeBlock::NoSignerException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* OfficeBlock::NoSignerException::what() const throw() {
	return "Office has no signer";
}

/* ========== NoExecutorException ========== */

OfficeBlock::NoExecutorException::NoExecutorException( void ) {}

OfficeBlock::NoExecutorException::NoExecutorException( OfficeBlock::NoExecutorException const & e ) {
	*this = e;
}

OfficeBlock::NoExecutorException::~NoExecutorException( void ) throw() {}

OfficeBlock::NoExecutorException &    OfficeBlock::NoExecutorException::operator=( OfficeBlock::NoExecutorException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* OfficeBlock::NoExecutorException::what() const throw() {
	return "Office has no executor";
}