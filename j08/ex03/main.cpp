#include <iostream>
#include "MindOpen.hpp"

int    main ( int ac, char** av ) {

	if ( ac != 2 ) {
		std::cout << "./MindOpen [file]" << std::endl;
		return (0);
	}

	MindOpen m( av[1] );
	m.readFile();
	m.executeProgram();

	return (0);
}