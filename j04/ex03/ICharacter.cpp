#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {
	return ;
};

ICharacter::ICharacter( ICharacter const & iCharacter ) {
	*this = iCharacter;
	return ;
};

ICharacter &    ICharacter::operator=( ICharacter const & rhs ) {
	( void )rhs;
	return (*this);
};