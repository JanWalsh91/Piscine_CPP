#include "AMateria.hpp"

#include <string>

AMateria::AMateria( void ) : xp_(0), type_("None") {}

AMateria::AMateria( std::string const & type ) : xp_(0), type_(type) {}

AMateria::AMateria( AMateria const & aMateria ) {
	*this = aMateria;
}

AMateria::~AMateria( void ) {}

AMateria &    AMateria::operator=( AMateria const & rhs ) {
	this->xp_ = rhs.xp_;
	return (*this);
}

std::string const & AMateria::getType( void ) const {
	return (this->type_);
}

unsigned int AMateria::getXP( void ) const {
	return (this->xp_);
}

void AMateria::use( ICharacter& target ) {
	( void )target;
	this->xp_ += 10;
}