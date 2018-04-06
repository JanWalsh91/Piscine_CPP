#include "PutChar.hpp"

PutChar::PutChar( void ) {
}

PutChar::PutChar( PutChar const & PutChar ) {
	*this = PutChar;
}

PutChar::~PutChar( void ) {}

PutChar & PutChar::operator=( PutChar const & rhs ) {
	( void )rhs;
	return *this;
}

void PutChar::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	std::cout << *cPtr;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}