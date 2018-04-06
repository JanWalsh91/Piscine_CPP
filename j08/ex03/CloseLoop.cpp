#include "CloseLoop.hpp"

CloseLoop::CloseLoop( void ) {
	// std::cout << "CloseLoop created" << std::endl;
}

CloseLoop::CloseLoop( CloseLoop const & CloseLoop ) {
	*this = CloseLoop;
}

CloseLoop::~CloseLoop( void ) {}

CloseLoop & CloseLoop::operator=( CloseLoop const & rhs ) {
	( void )rhs;
	return *this;
}

void CloseLoop::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	if ( *cPtr ) {
		// std::cout << "execute close loop" << std::endl;
		iPtr = this->getMatch();
	}
	// std::cout << "skip close loop" << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}

void CloseLoop::setMatchIndex( int i ) {
	this->matchIndex = i;
}

int CloseLoop::getMatchIndex( void ) const {
	return this->matchIndex;
}

void CloseLoop::setMatch( std::list<Instruction *>::iterator it ) {
	this->match = it;
}

std::list<Instruction *>::iterator CloseLoop::getMatch( void ) const {
	return this->match;
}