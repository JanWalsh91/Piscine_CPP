#include "MoveLeft.hpp"

MoveLeft::MoveLeft( void ) {
}

MoveLeft::MoveLeft( MoveLeft const & MoveLeft ) {
	*this = MoveLeft;
}

MoveLeft::~MoveLeft( void ) {}

MoveLeft & MoveLeft::operator=( MoveLeft const & rhs ) {
	( void )rhs;
	return *this;
}

void MoveLeft::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	if ( cPtr != chars.begin() ) {
		Instruction::execute( instructions, ++iPtr, chars, --cPtr );
	}
}