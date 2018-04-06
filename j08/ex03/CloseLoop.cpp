#include "CloseLoop.hpp"

CloseLoop::CloseLoop( void ) {
}

CloseLoop::CloseLoop( CloseLoop const & CloseLoop ) {
	*this = CloseLoop;
}

CloseLoop::~CloseLoop( void ) {}

CloseLoop & CloseLoop::operator=( CloseLoop const & rhs ) {
	( void )rhs;
	return *this;
}

void CloseLoop::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	if ( *cPtr ) {
		iPtr = this->getMatch();
	}
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}

void CloseLoop::setMatchIndex( int i ) {
	this->matchIndex = i;
}

int CloseLoop::getMatchIndex( void ) const {
	return this->matchIndex;
}

void CloseLoop::setMatch( std::vector<Instruction *>::iterator it ) {
	this->match = it;
}

std::vector<Instruction *>::iterator CloseLoop::getMatch( void ) const {
	return this->match;
}