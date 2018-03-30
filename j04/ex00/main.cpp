#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Noble.hpp"
#include "Prince.hpp"
#include "Politician.hpp"

#include <string>
#include <iostream>

int    main ( void ) {
	Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
	Peon joe("Joe");
	
	std::cout << robert << jim << joe;
	
	robert.polymorph(jim);
	robert.polymorph(joe);
	
	std::cout << "==========" << std::endl; 

	Noble thor("Thor");
	Prince thorin("Thorin");
	Politician trump("Trump");

	std::cout << thor << thorin << trump;

	robert.polymorph(thor);
	robert.polymorph(thorin);
	robert.polymorph(trump);

	std::cout << "==========" << std::endl; 
	return 0;
}