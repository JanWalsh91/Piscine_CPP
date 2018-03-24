#include "mutantstack.hpp"

#include <iostream>

template< typename T >
Mutantstack< T >::Mutantstack< T >( void ) {
	std::cout << "Default constructor called" << std::endl;
}

// Mutantstack::Mutantstack( Mutantstack const & Mutantstack ) {
// 	std::cout << "Copy constructor called" << std::endl;
// 	*this = Mutantstack;
// }

// Mutantstack::~Mutantstack( void ) {
// 	std::cout << "Destructor called" << std::endl;
// }

// Mutantstack &    Mutantstack::operator=( Mutantstack const & rhs ) {
// 	this->_i = rhs._i;
// 	return (*this);
// }