#include "IAsteroid.hpp"

#include <iostream>

IAsteroid::IAsteroid( void ) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
};

IAsteroid::IAsteroid( IAsteroid const & iAsteroid ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = iAsteroid;
	return ;
};

IAsteroid &    IAsteroid::operator=( IAsteroid const & rhs ) {
	( void )rhs;
	return (*this);
};