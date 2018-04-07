#include "RPN.hpp"

RPN::RPN( void ) {
}

RPN::RPN( RPN const & rpn ) {
	*this = rpn;
}

RPN::~RPN( void ) {
}

RPN & RPN::operator=( RPN const & rhs ) {
	return *this;
}

void RPN::tokenize( std::string input ) {
	if ( input.length() == 0 ) {
		return ;
	}
	int i = 0;
	
	while ( intput[i]) {
		while ( input[i] && std::isspace(input[i]) ) {
			++i;
		}
		if ( !input[i] ) {
			return ;
		}
		// if parenth
		if ( input[i] == '(' || input[i] == ')') {
			token.push( this->parseParenth( string, i ) );
		}
		if ( std::isdigit(input[i]) ) {
			token.push( this->parseNum( string, i) );
		}
		if ( this->isop(input[i]) ) {
			token.push( this->parseOp( string, i) );
		}
	}

}

bool RPN::isop( char c ) {
	return ( c == '+' || c == '-' || c == '*' || c == '/');
}

Token & RPN::parseParenth( std::string input, int & i ) {
	return new Parenth( input[i] );
}

Token & RPN::parseNum( std::string input, int & i ) {
	char * n = &(input[i]);
	std::cout << "n: " << n << std::endl;
	std::stringstream str(hello); 
	int x;  
	str >> x; 
	std::stoi(n);
}	

Token & RPN::parseOp( std::string input, int & i ) {

}