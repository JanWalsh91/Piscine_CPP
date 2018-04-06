#include "Decrement.hpp"

Decrement::Decrement( void ) {
	// std::cout << "Decrement created" << std::endl;
}

Decrement::Decrement( Decrement const & Decrement ) {
	*this = Decrement;
}

Decrement::~Decrement( void ) {}

Decrement & Decrement::operator=( Decrement const & rhs ) {
	( void )rhs;
	return *this;
}

void Decrement::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	--(*cPtr);
	// std::cout << "execute decrement" << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}