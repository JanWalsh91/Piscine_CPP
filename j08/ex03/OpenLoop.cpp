#include "OpenLoop.hpp"

OpenLoop::OpenLoop( void ) {
	// std::cout << "OpenLoop created" << std::endl;
}

OpenLoop::OpenLoop( OpenLoop const & OpenLoop ) {
	*this = OpenLoop;
}

OpenLoop::~OpenLoop( void ) {}

OpenLoop & OpenLoop::operator=( OpenLoop const & rhs ) {
	( void )rhs;
	return *this;
}

void OpenLoop::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	( void )iPtr;
	( void )chars;
	( void )cPtr;
	if ( !*cPtr ) {
		// std::cout << "execute open loop" << std::endl;
		iPtr = this->getMatch();
	}
	// std::cout << "skip open loop" << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}

void OpenLoop::setMatchIndex( int i ) {
	this->matchIndex = i;
}

int OpenLoop::getMatchIndex( void ) const {
	return this->matchIndex;
}

void OpenLoop::setMatch( std::list<Instruction *>::iterator it ) {
	this->match = it;
}

std::list<Instruction *>::iterator OpenLoop::getMatch( void ) const {
	return this->match;
}