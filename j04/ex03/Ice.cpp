#include "Ice.hpp"

#include <iostream>

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( Ice const & ice ) : AMateria("ice") {
	*this = ice;
}

Ice::~Ice( void ) {}

Ice &    Ice::operator=( Ice const & rhs ) {
	this->xp_ = rhs.xp_;
	return (*this);
}

Ice* Ice::clone( void ) const {
	Ice* ice = new Ice();
	ice->xp_ = this->xp_;
	return ( ice );
}

void	Ice::use( ICharacter& target ) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}