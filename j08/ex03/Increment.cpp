#include "Increment.hpp"

Increment::Increment( void ) {
	// std::cout << "Increment created" << std::endl;
}

Increment::Increment( Increment const & Increment ) {
	*this = Increment;
}

Increment::~Increment( void ) {}

Increment & Increment::operator=( Increment const & rhs ) {
	( void )rhs;
	return *this;
}

void Increment::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	++(*cPtr);
	// std::cout << "execute increment" << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}