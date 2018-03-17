#include "Ice.hpp"
#include "ICharacter.hpp"

#include <iostream>

Ice::Ice( void ) : AMateria("ice") {
	return ;
};

Ice::Ice( Ice const & ice ) : AMateria("ice") {
	*this = ice;
	return ;
};

Ice::~Ice( void ) {
	return ;
};

Ice &    Ice::operator=( Ice const & rhs ) {
	this->xp_ = rhs.xp_;
	return (*this);
};

Ice* Ice::clone( void ) const {
	return (new Ice());
}

void	Ice::use( ICharacter& target ) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};