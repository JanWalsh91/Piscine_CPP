#include "Input.hpp"

#include <iostream>

Input::Input( void ) : _input( NULL ) {
	
	return ;
};

Input::Input( std::string input ) {
	// check if int
	try {
		int *i = new int( std::stoi( input ) );
		
		if ( std::to_string(*i) == input ) {
			// input is int
			this->_type = "int";
			this->_input = reinterpret_cast<void *>( i );
			return ;
		}
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	};
	
	// check if char
	if ( input.length() == 1 ) {
		std::cout << "char " << std::endl;
		char *c = new char( static_cast<char>( input[0] ) );
		this->_type = "char";
		this->_input = static_cast<void *>( c );
		return ;
	}
	// check if float (has 'f')
	if ( input[input.length() - 1] == 'f' || 
		input == "-inff" ||
		input == "+inff" ||
		input == "nanf") {
		try {
			float *f = new float( std::stof( input ) );
			this->_type = "float";
			this->_input = static_cast<void *>( f );
			std::cout << "--- storing:  " << *(static_cast<float *>(this->_input) ) << std::endl;
			return ;
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		};
	}
	// check if double
	if ( std::isdigit(input[input.length() - 1]) || 
		input == "-inf" ||
		input == "+inf" ||
		input == "nan") {
		try {
			double *d = new double( std::stod( input ) );
			std::cout << std::to_string( *d ) << std::endl;
			this->_type = "double";
			this->_input = reinterpret_cast<void *>( d );
			return ;
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		};
	}
	return ;
	// throw invalid expression
};

Input::Input( Input const & input ) {
	*this = input;
	return ;
};

Input::~Input( void ) {
	if ( this->_type == "int") {
		// std::cout << "free int" << std::endl; 
		delete reinterpret_cast<int *>(this->_input);
	}
	if ( this->_type == "char") {
		// std::cout << "free char" << std::endl; 
		delete reinterpret_cast<char *>(this->_input);
	}
	if ( this->_type == "float") {
		// std::cout << "free float" << std::endl; 
		delete reinterpret_cast<float *>(this->_input);
	}
	if ( this->_type == "double") {
		// std::cout << "free double" << std::endl; 
		delete reinterpret_cast<double *>(this->_input);
	}
	return ;
};

void *	Input::getInput( void ) const {
	// std::cout << "getInput: " << this->_input << std::endl;
	return this->_input;
};

std::string	Input::getType( void ) const {
	return this->_type;
};

Input::operator char( void ) {
	if ( this->getType() == "char") {
		return *( static_cast<char *>( this->getInput()) );
	}
	if ( this->getType() == "int") {
		int i = *static_cast<int *>( this->getInput());
		if ( i < std::numeric_limits<char>::min() ||
			i > std::numeric_limits<char>::max() ) {
			throw( Input::OverflowException() );
		}
		char c = char( i );
		return c;
	}
	if ( this->getType() == "float") {
		float f = *static_cast<float *>( this->getInput());
		if ( f < std::numeric_limits<char>::min() ||
			f > std::numeric_limits<char>::max() ) {
			throw( Input::OverflowException() );
		}
		char c = char( f );
		return c;
	}
	if ( this->getType() == "double") {
		double d = *static_cast<double *>( this->getInput());
		if ( d < std::numeric_limits<char>::min() ||
			d > std::numeric_limits<char>::max() ) {
			throw( Input::OverflowException() );
		}
		char c = char( d );
		return c;
	}
	return '0';
};

Input::operator int( void ) {
	if ( this->getType() == "char") {
		int i = int( *reinterpret_cast<int *>( this->getInput()) );
		return i;
	}
	if ( this->getType() == "int") {
		return *( static_cast<int *>( this->getInput()) );
	}
	if ( this->getType() == "float") {
		float f = *static_cast<float *>( this->getInput());
		if ( f < std::numeric_limits<int>::min() ||
			f > std::numeric_limits<int>::max() ) {
			throw( Input::OverflowException() );
		}	
		return f;
	}
	if ( this->getType() == "double") {
		double d = *static_cast<double *>( this->getInput());
		if ( d < std::numeric_limits<int>::min() ||
			d > std::numeric_limits<int>::max() ) {
			throw( Input::OverflowException() );
		}	
		return d;
	}
	return 0;
};

Input::operator float( void ) {
	if ( this->getType() == "char") {
		int i = int( *reinterpret_cast<int *>( this->getInput()) );
		return i;
	}
	if ( this->getType() == "int") {
		return *( static_cast<int *>( this->getInput()) );
	}
	if ( this->getType() == "float") {
		return *( static_cast<float *>( this->getInput()) );
	}
	if ( this->getType() == "double") {
		double d = *static_cast<double *>( this->getInput());
		std::cout << std::fixed;
		std::cout << "------double: " << d << std::endl;
		std::cout << std::numeric_limits<float>::max() << std::endl;
		std::cout << (d > std::numeric_limits<float>::max()) << std::endl;

		if ( d < std::numeric_limits<float>::min() ||
			d > std::numeric_limits<float>::max() ) {
			throw( Input::OverflowException() );
		}	
		return d;
	}
	return 0.0f;
};

Input::operator double( void ) {
	if ( this->getType() == "char") {
		int i = int( *reinterpret_cast<int *>( this->getInput()) );
		return i;
	}
	if ( this->getType() == "int") {
		return *( static_cast<int *>( this->getInput()) );
	}
	if ( this->getType() == "float") {
		return *( static_cast<float *>( this->getInput()) );
	}
	if ( this->getType() == "double") {
		return *( static_cast<double *>( this->getInput()) );
	}
	return 0.0f;
};

const char* Input::OverflowException::what() const throw() {
	return "impossible";
};

Input &    Input::operator=( Input const & rhs ) {
	this->_input = rhs._input;
	return (*this);
};

std::ostream& operator<<(std::ostream & os, const Input & input) {
	if ( input.getType() == "int" ) {
		os << *( reinterpret_cast<int *>( input.getInput() ) );
	}
	else if ( input.getType() == "char" ) {
		std::cout << "char: ";
		os << *( reinterpret_cast<char *>( input.getInput()  ));
	}
	else if ( input.getType() == "float" ) {
		std::cout << "float: ";
		os << *( reinterpret_cast<float *>( input.getInput() ) );
	}
	else if ( input.getType() == "double" ) {
		std::cout << "double: ";
		os << *( reinterpret_cast<double *>( input.getInput( )) );
	}
	return os;
};