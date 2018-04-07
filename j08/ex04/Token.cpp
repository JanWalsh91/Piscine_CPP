#include "Token.hpp"

Token::Token( void ) {
}

Token::Token( Token const & token ) {
	*this = token;
}

Token::~Token( void ) {
}

Token & Token::operator=( Token const & rhs ) {
	return *this;
}