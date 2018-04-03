#include "Input.hpp"

#include <iostream>
#include <string>
#include <exception>

int    main ( int ac, char** av ) {

	if ( ac != 2 ) {
		std::cout << "Please execute with one parameter." << std::endl;
		return (0);
	}

	Input* input = new Input(av[1]);

	std::cout << "You entered: [ " << *input << " ]" << " of type [ " << input->getType() << " ]" << std::endl << std::endl;

	char c; 
	try {
		c = static_cast<char>(*input);
		if ( std::isprint (c) ) {
			std::cout << "char: " << c << std::endl;
		}
		else {
			std::cout << "char: " << "Non displayable" << std::endl;
		}
	}
	catch ( std::exception &e ) {
		std::cout << "char: " << e.what() << std::endl;
	} 

	std::cout << "int: ";
	int i;
	try {
		i = static_cast<int>(*input);
	 	std::cout << i << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	} 
	
	std::cout << "float: ";
	int f;
	try {
		f = static_cast<float>(*input);
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << f << 'f' << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	} 

	double d = static_cast<double>(*input);
	std::cout << "double: " << d << std::endl;

	delete input;

	return (0);
}