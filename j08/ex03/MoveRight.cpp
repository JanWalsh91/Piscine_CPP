#include "MoveRight.hpp"

MoveRight::MoveRight( void ) {
}

MoveRight::MoveRight( MoveRight const & MoveRight ) {
	*this = MoveRight;
}

MoveRight::~MoveRight( void ) {}

MoveRight & MoveRight::operator=( MoveRight const & rhs ) {
	( void )rhs;
	return *this;
}

void MoveRight::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	++cPtr;
	if ( cPtr == chars.end() ) {
		chars.push_back(0);
	}
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}