#include "Parenth.hpp"

Parenth::Parenth( void ) {}

Parenth::Parenth( char c ) : value(c){}

Parenth::Parenth( Parenth const & parenth ) {
	*this = parenth;
}

Parenth::~Parenth( void ) {
}

Parenth & Parenth::operator=( Parenth const & rhs ) {
	return *this;
}