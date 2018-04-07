#include "Operator.hpp"

Operator::Operator( void ) {}

Operator::Operator( char c ) : value(c) {
	if ( c == '+' || c == '-' ) {
		this->priority = 1;
	}
	else {
		this->priority = 2;
	}
}

Operator::Operator( Operator const & op ) {
	*this = op;
}

Operator::~Operator( void ) {}

Operator & Operator::operator=( Operator const & rhs ) {
	*this->value = rhs.value;
	*this->priority = rhs.priority;
	return *this;
}