#include "Instruction.hpp"

#include <iterator>

Instruction::Instruction( void ) {}

Instruction::Instruction( Instruction const & instruction ) {
	*this = instruction;
}

Instruction::~Instruction( void ) {}

Instruction & Instruction::operator=( Instruction const & rhs ) {
	( void )rhs;
	return *this;
}

void Instruction::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	if ( iPtr != instructions.end() ) {
		(*iPtr)->execute( instructions, iPtr, chars, cPtr );
	}
}