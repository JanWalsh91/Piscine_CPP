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

void Increment::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	++(*cPtr);
	// std::cout << "increment: " << *cPtr << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}