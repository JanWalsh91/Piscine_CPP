#include "OpenLoop.hpp"

OpenLoop::OpenLoop( void ) {
}

OpenLoop::OpenLoop( OpenLoop const & OpenLoop ) {
	*this = OpenLoop;
}

OpenLoop::~OpenLoop( void ) {}

OpenLoop & OpenLoop::operator=( OpenLoop const & rhs ) {
	( void )rhs;
	return *this;
}

void OpenLoop::execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	if ( !*cPtr ) {
		iPtr = this->getMatch();
	}
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}

void OpenLoop::setMatchIndex( int i ) {
	this->matchIndex = i;
}

int OpenLoop::getMatchIndex( void ) const {
	return this->matchIndex;
}

void OpenLoop::setMatch( std::vector<Instruction *>::iterator it ) {
	this->match = it;
}

std::vector<Instruction *>::iterator OpenLoop::getMatch( void ) const {
	return this->match;
}