#include "Input.hpp"

#include <iostream>

Input::Input( void ) {}

Input::Input( std::string input ) : _type(""), _char(' '), _int(0), _float(0.0), _double(0.0), _impossible(false) {
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
	try {
		int i = std::stoi( input );	
		if ( std::to_string(i) == input ) {
			this->_type = "int";
			this->_int = i;
			return ;
		}
	}
	catch ( std::exception &e ) {}
	
	// check if char
	if ( this->_type == "" && input.length() == 1 ) {
		char c = static_cast<char>( input[0] );
		this->_type = "char";
		this->_char = c;
		return ;
	}

	// check if float (has 'f')
	if ( this->_type == "" && ( (input[input.length() - 1] == 'f' && std::isdigit(input[input.length() - 2]))  || 
		input == "-inff" ||
		input == "+inff" ||
		input == "inff" ||
		input == "nanf")) {
		try {
			float f( std::stof( input ) );
			this->_type = "float";
			this->_float = static_cast<float>( f );
			return ;
		}
		catch ( std::exception &e ) {}
	}

	// check if double 
	if ( this->_type == "" && (std::isdigit(input[input.length() - 1]) || 
		input == "inf" ||
		input == "-inf" ||
		input == "+inf" ||
		input == "nan")) {
		try {
			double d( std::stod( input ) );
			this->_type = "double";
			this->_double = static_cast<double>( d );
			return ;
		}
		catch ( std::exception & e ) {}
	}
	throw( Input::InvalidInputException());
}

Input::Input( Input const & input ) {
	*this = input;
}

Input::~Input( void ) {}

std::string	Input::getType( void ) const {
	return this->_type;
}

Input &    Input::operator=( Input const & rhs ) {
	this->_type = rhs._type;
	this->_char = rhs._char;
	this->_int = rhs._int;
	this->_float = rhs._float;
	this->_double = rhs._double;
	this->_impossible = rhs._impossible;
	return (*this);
}

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
		if ( this->_impossible ) {
			convert << static_cast<float>(this->_double); 
		}
		else if ( this->_double < std::numeric_limits<float>::min() ||
			this->_double > std::numeric_limits<float>::max() ) {
				return "impossible";
		}
		else {
			convert << static_cast<float>(this->_double);
		}
	}
	convert << "f";
	return convert.str();
}

std::string Input::getDouble( void ) {
	std::ostringstream convert;
	convert << std::fixed;
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