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

void Instruction::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	std::cout << "Instruction: execute" << std::endl;

	// chars.push_back(97);
	// std::cout << *cPtr << std::endl;
	// ++cPtr;
	// std::cout << *cPtr << std::endl;

	// exit(0);
	// ( void )iPtr;
	// ( void )chars;
	// ( void )cPtr;
	// ( void )instructions;
	if ( iPtr != instructions.end() ) {
		(*iPtr)->execute( instructions, iPtr, chars, cPtr );
	}
	else {
		std::cout << "Done" << std::endl;
	}
}