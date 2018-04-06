#include "MoveLeft.hpp"

MoveLeft::MoveLeft( void ) {
	// std::cout << "MoveLeft created" << std::endl;
}

MoveLeft::MoveLeft( MoveLeft const & MoveLeft ) {
	*this = MoveLeft;
}

MoveLeft::~MoveLeft( void ) {}

MoveLeft & MoveLeft::operator=( MoveLeft const & rhs ) {
	( void )rhs;
	return *this;
}

void MoveLeft::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	if ( cPtr != chars.begin() ) {
		// std::cout << "execute move left" << std::endl;
		Instruction::execute( instructions, ++iPtr, chars, --cPtr );
	}
}