#include <iostream>
#include "MindOpen.hpp"

int    main ( int ac, char** av ) {

	// if ( ac == 1 ) {
	// 	// readfrom command line
	// 	std::cout << "Reading from command line" << std::endl;
	// 	return (0);
	// }

	// std::list<int>						ints;
	// std::list<int>::iterator			iPtr;
	// ints.push_back(0);
	// iPtr = ints.begin();
	// std::cout << *iPtr << std::endl;
	// ints.push_back(5);
	// ++iPtr;
	// std::cout << *iPtr << std::endl;

	// return 0;

	

	if ( ac != 2 ) {
		std::cout << "./MindOpen [file]" << std::endl;
		return (0);
	}

	MindOpen m( av[1] );
	m.readFile();
	m.executeProgram();

	return (0);
}