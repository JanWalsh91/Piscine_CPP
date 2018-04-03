#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

int    main ( void ) {
	std::srand(std::time(nullptr));

	// Create the Central Bureaucracy
	CentralBureaucracy central;

	// Create 20 random bureaucrats and feed them to the Central Bureaucracy
	std::string names[] = {"Donald Doss", "Lynwood Lirette", "Maynard Macintosh", "Omar Owings", "Abe Anderton", "Jordan Johnson",
	"Woodrow Wolfenbarger", "Brooks Broach", "Arnulfo Adkinson", "Steve Schumann", "Ivory Iverson", "Desmond Daniele", "Antony Aziz",
	"Ali Arizmendi", "Cyril Casseus", "Leo Larocco", "Milo Mcdivitt", "Willy Wickwire", "Tyree Tomasello", "Marion Milan"};
	for ( int i = 0; i < 20; i++ ) {
		Bureaucrat *b1;
		try {
			b1 = new Bureaucrat( names[std::rand() % 20], std::rand() % 150);		
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

	// Queue up a large number of targets in the Central Bureaucracy
	std::string targets[] = {"Angel", "Bob", "Cherry", "HaoDing", "ClapTrap"};
	for ( int i = 0; i < 10; ++i ) {
		central.queueUp( targets[ std::rand() % 5 ] );
	}

	// Call the doBureaucracy function and watch magic happen
	try {
		central.doBureaucracy();
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}