#include "Cure.hpp"

#include <iostream>

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( Cure const & cure ) : AMateria("cure") {
	*this = cure;
}

Cure::~Cure( void ) {}

Cure &    Cure::operator=( Cure const & rhs ) {
	this->xp_ = rhs.xp_;
	return (*this);
}

Cure* Cure::clone( void ) const {
	Cure* cure = new Cure();
	cure->xp_ = this->xp_;
	return ( cure );
}

void	Cure::use( ICharacter& target ) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl;
}