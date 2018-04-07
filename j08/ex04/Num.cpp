#include "Num.hpp"

Num::Num( void ) {}

Num::Num( int i ) : value(i) {}

Num::Num( Num const & num ) {
	*this = num;
}

Num::~Num( void ) {}

Num & Num::operator=( Num const & rhs ) {
	this->value = rhs.value;
	return *this;
}