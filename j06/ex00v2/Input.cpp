#include "Input.hpp"

#include <iostream>

Input::Input( void ) {}

Input::Input( std::string input ) {
	if (input == "-inf" ||
	input == "+inf" ||
	input == "inf" ||
	input == "nan" ||
	input == "-inff" ||
	input == "+inff" ||
	input == "inff" ||
	input == "nanf") {
		this->_impossible = true;
	}
	// check if int
	this->_type = "";
	// std::cout << "Check if int" << std::endl;
	try {
		int i = std::stoi( input );	
		if ( std::to_string(i) == input ) {
			// input is int
			this->_type = "int";
			this->_int = i;
			return ;
		}
	}
	catch ( std::exception &e ) {
		// std::cout << e.what() << std::endl;
	}
	
	// check if char
	// std::cout << "Check if char" << std::endl;
	if ( this->_type == "" && input.length() == 1 ) {
		// std::cout << "char " << std::endl;
		char c = static_cast<char>( input[0] );
		this->_type = "char";
		this->_char = c;
		return ;
	}
	// check if float (has 'f')
	// std::cout << "Check if float" << std::endl;
	if ( this->_type == "" && ( (input[input.length() - 1] == 'f' && std::isdigit(input[input.length() - 2]))  || 
		input == "-inff" ||
		input == "+inff" ||
		input == "inff" ||
		input == "nanf")) {
		try {
			float f( std::stof( input ) );
			this->_type = "float";
			this->_float = static_cast<float>( f );
			// std::cout << "--- storing:  " << *(static_cast<float *>(this->_input) ) << std::endl;
			return ;
		}
		catch ( std::exception &e ) {
			// std::cout << e.what() << std::endl;
		}
	}
	// check if double 
	// std::cout << "Check if double" << std::endl;
	if ( this->_type == "" && (std::isdigit(input[input.length() - 1]) || 
		input == "inf" ||
		input == "-inf" ||
		input == "+inf" ||
		input == "nan")) {
		try {
			double d( std::stod( input ) );
			// std::cout << std::to_string( *d ) << std::endl;
			this->_type = "double";
			this->_double = static_cast<double>( d );
			return ;
		}
		catch ( std::exception & e ) {
			// std::cout << e.what() << std::endl;
		}
	}

	throw( Input::InvalidInputException());
}

Input::Input( Input const & input ) {
	*this = input;
	return ;
}

Input::~Input( void ) {}

// void *	Input::getInput( void ) const {
// 	return this->_input;
// }

std::string	Input::getType( void ) const {
	return this->_type;
}

// /* ========== Cast Char ========== */

// Input::operator char( void ) {
// 	if ( this->getType() == "char") {
// 		return *( static_cast<char *>( this->getInput()) );
// 	}
// 	if ( this->getType() == "int") {
// 		int i = *static_cast<int *>( this->getInput());
// 		if ( i < std::numeric_limits<char>::min() ||
// 			i > std::numeric_limits<char>::max() ) {
// 			throw( Input::InvalidInputException() );
// 		}
// 		char c = char( i );
// 		return c;
// 	}
// 	if ( this->getType() == "float") {
// 		float f = *static_cast<float *>( this->getInput());
// 		if ( f < std::numeric_limits<char>::min() ||
// 			f > std::numeric_limits<char>::max() ) {
// 			throw( Input::InvalidInputException() );
// 		}
// 		char c = char( f );
// 		return c;
// 	}
// 	if ( this->getType() == "double") {
// 		double d = *static_cast<double *>( this->getInput());
// 		if ( d < std::numeric_limits<char>::min() ||
// 			d > std::numeric_limits<char>::max() ) {
// 			throw( Input::InvalidInputException() );
// 		}
// 		char c = char( d );
// 		return c;
// 	}
// 	return '0';
// }

// /* ========== Cast Int ========== */

// Input::operator int( void ) {
// 	if ( this->getType() == "char") {
// 		int i = int( *reinterpret_cast<int *>( this->getInput()) );
// 		return i;
// 	}
// 	if ( this->getType() == "int") {
// 		return *( static_cast<int *>( this->getInput()) );
// 	}
// 	if ( this->getType() == "float") {
// 		float f = *static_cast<float *>( this->getInput());
// 		if ( f < std::numeric_limits<int>::min() ||
// 			f > std::numeric_limits<int>::max() ) {
// 			throw( Input::InvalidInputException() );
// 		}	
// 		return f;
// 	}
// 	if ( this->getType() == "double") {
// 		double d = *static_cast<double *>( this->getInput());
// 		if ( d < std::numeric_limits<int>::min() ||
// 			d > std::numeric_limits<int>::max() ) {
// 			throw( Input::InvalidInputException() );
// 		}	
// 		return d;
// 	}
// 	return 0;
// }

// /* ========== Cast Float ========== */

// Input::operator float( void ) {
// 	if ( this->getType() == "char") {
// 		int i = int( *reinterpret_cast<int *>( this->getInput()) );
// 		return i;
// 	}
// 	if ( this->getType() == "int") {
// 		return *( static_cast<int *>( this->getInput()) );
// 	}
// 	if ( this->getType() == "float") {
// 		return *( static_cast<float *>( this->getInput()) );
// 	}
// 	if ( this->getType() == "double") {
// 		// double d = static_cast<float>(*static_cast<double *>( this->getInput()));
// 		double d = (*static_cast<double *>( this->getInput()));
// 		// std::cout << std::fixed;
// 		// std::cout << "------double: " << d << std::endl;
// 		// std::cout << std::numeric_limits<float>::max() << std::endl;
// 		// std::cout << (d > std::numeric_limits<float>::max()) << std::endl;

// 		if ( d < std::numeric_limits<float>::min() ||
// 			d > std::numeric_limits<float>::max() ) {
// 			throw( Input::InvalidInputException() );
// 		}
// 		return d;
// 	}
// 	return 0.0f;
// }

// /* ========== Cast Double ========== */

// Input::operator double( void ) {
// 	if ( this->getType() == "char") {
// 		int i = int( *reinterpret_cast<int *>( this->getInput()) );
// 		return i;
// 	}
// 	if ( this->getType() == "int") {
// 		return *( static_cast<int *>( this->getInput()) );
// 	}
// 	if ( this->getType() == "float") {
// 		return *( static_cast<float *>( this->getInput()) );
// 	}
// 	if ( this->getType() == "double") {
// 		return *( static_cast<double *>( this->getInput()) );
// 	}
// 	return 0.0f;
// }


Input &    Input::operator=( Input const & rhs ) {
	// this->_input = rhs._input;
	( void )rhs;
	return (*this);
}

// std::ostream& operator<<(std::ostream & os, const Input & input) {
// 	if ( input.getType() == "int" ) {
// 		os << *( reinterpret_cast<int *>( input.getInput() ) );
// 	}
// 	else if ( input.getType() == "char" ) {
// 		// std::cout << "char: ";
// 		os << *( reinterpret_cast<char *>( input.getInput()  ));
// 	}
// 	else if ( input.getType() == "float" ) {
// 		// std::cout << "float: ";
// 		os << *( reinterpret_cast<float *>( input.getInput() ) );
// 	}
// 	else if ( input.getType() == "double" ) {
// 		// std::cout << "double: ";
// 		os << *( reinterpret_cast<double *>( input.getInput( )) );
// 	}
// 	return os;
// }

/* ========== InvalidInputException ========== */

Input::InvalidInputException::InvalidInputException( void ) {}

Input::InvalidInputException::InvalidInputException( Input::InvalidInputException const & e ) {
	*this = e;
}

Input::InvalidInputException::~InvalidInputException( void ) throw() {}

Input::InvalidInputException &    Input::InvalidInputException::operator=( Input::InvalidInputException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* Input::InvalidInputException::what() const throw() {
	return "Invalid input";
}

std::string Input::getInt( void ) {
	if ( this->_impossible ) {
		return "impossible";
	}
	std::ostringstream convert;

	if ( this->_type == "int" ) {
		convert << this->_int;
	}
	if ( this->_type == "char" ) {
		convert << static_cast<int>(this->_char);
	}
	if ( this->_type == "float" ) {
		if ( this->_float < std::numeric_limits<int>::min() ||
			this->_float > std::numeric_limits<int>::max() ) {
				return "impossible";
		}
		convert << static_cast<int>(this->_float);
	}
	if ( this->_type == "double" ) {
		if ( this->_double < std::numeric_limits<int>::min() ||
			this->_double > std::numeric_limits<int>::max() ) {
				return "impossible";
		}
		convert << static_cast<int>(this->_double);
	}
	return convert.str();
}

std::string Input::getChar( void ) {
	// HANDLE NON DISPLYABLE
	// HANDLE IMPOSSIBLE
	if ( this->_impossible ) {
		return "impossible";
	}
	std::ostringstream convert;
	char c;
	if ( this->_type == "char" ) {
		c = this->_char;
	}
	if ( this->_type == "int" ) {
		if ( this->_int < std::numeric_limits<char>::min() ||
			this->_int > std::numeric_limits<char>::max() ) {
				return "impossible";
		}
		c = static_cast<char>(this->_int);
	}
	if ( this->_type == "float" ) {
		if ( this->_float < std::numeric_limits<char>::min() ||
			this->_float > std::numeric_limits<char>::max() ) {
				return "impossible";
		}
		c = static_cast<char>(this->_float);
	}
	if ( this->_type == "double" ) {
		if ( this->_double < std::numeric_limits<char>::min() ||
			this->_double > std::numeric_limits<char>::max() ) {
				return "impossible";
		}
		c = static_cast<char>(this->_double);
	}
	if ( std::isprint(c) ) {
		convert << c;
	}
	else {
		return "Non displayable";
	}
	return convert.str();
}

std::string Input::getFloat( void ) {
	std::ostringstream convert;
	convert << std::fixed;
	convert.precision(1);
	if ( this->_type == "float" ) {
		convert << this->_float;
	}
	if ( this->_type == "char" ) {
		convert << static_cast<float>(this->_char);
	}
	if ( this->_type == "int" ) {
		convert << static_cast<float>(this->_int);
	}
	if ( this->_type == "double" ) {
		if ( this->_double < std::numeric_limits<float>::min() ||
			this->_double > std::numeric_limits<float>::max() ) {
				return "impossible";
		}
		convert << static_cast<float>(this->_double);
	}
	convert << "f";
	return convert.str();
}

std::string Input::getDouble( void ) {
	std::ostringstream convert;
	convert << std::fixed;
	convert.precision(1);
	if ( this->_type == "double" ) {
		convert << this->_double;
	}
	if ( this->_type == "char" ) {
		convert << static_cast<double>(this->_char);
	}
	if ( this->_type == "int" ) {
		convert << static_cast<double>(this->_int);
	}
	if ( this->_type == "float" ) {
		convert << static_cast<double>(this->_float);
	}
	return convert.str();
}