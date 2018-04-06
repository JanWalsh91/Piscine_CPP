#include "GetInput.hpp"
#include <iostream>

GetInput::GetInput( void ) {
	// std::cout << "GetInput created" << std::endl;
}

GetInput::GetInput( GetInput const & GetInput ) {
	*this = GetInput;
}

GetInput::~GetInput( void ) {}

GetInput & GetInput::operator=( GetInput const & rhs ) {
	( void )rhs;
	return *this;
}

void GetInput::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	// std::cout << "Enter a character: ";
	std::cin >> *cPtr;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}