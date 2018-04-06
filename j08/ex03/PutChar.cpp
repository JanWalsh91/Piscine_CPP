#include "PutChar.hpp"

PutChar::PutChar( void ) {
	// std::cout << "PutChar created" << std::endl;
}

PutChar::PutChar( PutChar const & PutChar ) {
	*this = PutChar;
}

PutChar::~PutChar( void ) {}

PutChar & PutChar::operator=( PutChar const & rhs ) {
	( void )rhs;
	return *this;
}

void PutChar::execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr ) {
	// std::cout << "execute putchar" << std::endl;
	// ( void )iPtr;
	// ( void )chars;
	// ( void )instructions;
	// ( void )cPtr;
	// std::cout << *cPtr;
	std::cout << "Print: " << *cPtr << std::endl;
	std::cout << "\tAsci: "<< *(reinterpret_cast<int *>(&(*cPtr))) << std::endl;
	std::cout << "\tIndex: " << std::distance(chars.begin(), cPtr) << std::endl;
	Instruction::execute( instructions, ++iPtr, chars, cPtr );
}