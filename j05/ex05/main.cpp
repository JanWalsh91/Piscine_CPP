#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

int    main ( void ) {
	// test a lot , may segfault....
	CentralBureaucracy central;


	for ( int i = 0; i < 20; i++ ) {
		Bureaucrat b1 = Bureaucrat("B", 100);
		Bureaucrat b2 = Bureaucrat("B", 20);

		central.addBureaucrat(b1);
		central.addBureaucrat(b2);
		std::ostringstream oss;
		oss << i;
		central.queueUp( oss.str() );
	}

	central.doBureaucracy();

	return (0);
}