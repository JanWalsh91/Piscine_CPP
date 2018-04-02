#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

int    main ( void ) {
	CentralBureaucracy central;
	std::srand(std::time(nullptr));

	int y;
	for ( int i = 0; i < 50; i++ ) {
		y = std::rand() % 160;
		Bureaucrat *b1;
		try {
			b1 = new Bureaucrat("B", y);		
		}
		catch ( std::exception & e ) {
			std::cout << e.what() << std::endl;
			continue ;
		}
		try {
			central.addBureaucrat(*b1);
		}
		catch ( std::exception & e ) {
			std::cout << e.what() << std::endl;
		}
	}

	std::string targets[] = {"Angel", "Bob", "Cherry"};
	for ( int i = 0; i < 10; ++i ) {
		central.queueUp( targets[ std::rand() % 3 ] );
	}

	try {
		central.doBureaucracy();
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}