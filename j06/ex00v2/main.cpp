#include "Input.hpp"

#include <iostream>
#include <string>
#include <exception>

int    main ( int ac, char** av ) {

	if ( ac != 2 ) {
		std::cout << "Please execute with one parameter." << std::endl;
		return (0);
	}

	try {
		Input input(av[1]);

		std::cout << "You entered: [ " << av[1] << " ]" << " of type [ " << input.getType() << " ]" << std::endl << std::endl;

		std::cout << "char: " << input.getChar() << std::endl;
		std::cout << "int: " << input.getInt() << std::endl;
		std::cout << "float: " << input.getFloat() << std::endl;
		std::cout << "double: " << input.getDouble() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}