#include "Increment.hpp"

Increment::Increment( void ) {
}

Increment::Increment( Increment const & Increment ) {
	*this = Increment;
}

Increment::~Increment( void ) {}

Increment & Increment::operator=( Increment const & rhs ) {
	( void )rhs;
	return *this;
}

void Increment::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	++(*cPtr);
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}