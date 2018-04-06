#include "Decrement.hpp"

Decrement::Decrement( void ) {
}

Decrement::Decrement( Decrement const & Decrement ) {
	*this = Decrement;
}

Decrement::~Decrement( void ) {}

Decrement & Decrement::operator=( Decrement const & rhs ) {
	( void )rhs;
	return *this;
}

void Decrement::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	--(*cPtr);
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}