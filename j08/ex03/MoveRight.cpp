#include "MoveRight.hpp"

MoveRight::MoveRight( void ) {
	// std::cout << "MoveRight created" << std::endl;
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
	// ( void )iPtr;
	// ( void )cPtr;
	// std::cout << "execute move right" << std::endl;
	// std::cout << "Move Right" << std::endl;
	// std::cout << "\tcurrent value: " << *(reinterpret_cast<int *>(&(*cPtr))) << std::endl;
	++cPtr;
	if ( cPtr == chars.end() ) {
		// std::cout << "\tadding char. ";
		chars.push_back(0);
		// for ( int i = 0; i < 3; ++i ) {
		// 	std::cout << chars[i] << std::endl;
		// }
		// std::cout << "New length: " << chars.size() << std::endl;
	}
	// std::cout << "\tnew value: " << *(reinterpret_cast<int *>(&(*cPtr))) << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}