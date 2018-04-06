#include "GetInput.hpp"
#include <iostream>

GetInput::GetInput( void ) {
}

GetInput::GetInput( GetInput const & GetInput ) {
	*this = GetInput;
}

GetInput::~GetInput( void ) {}

GetInput & GetInput::operator=( GetInput const & rhs ) {
	( void )rhs;
	return *this;
}

void GetInput::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	std::cin >> *cPtr;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}