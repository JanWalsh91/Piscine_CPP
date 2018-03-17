#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

Cure::Cure( void ) : AMateria("cure") {
	return ;
};

Cure::Cure( Cure const & cure ) : AMateria("cure") {
	*this = cure;
	return ;
};

Cure::~Cure( void ) {
	return ;
};

Cure &    Cure::operator=( Cure const & rhs ) {
	this->xp_ = rhs.xp_;
	return (*this);
};

Cure* Cure::clone( void ) const {
	return (new Cure());
}

void	Cure::use( ICharacter& target ) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl;
};