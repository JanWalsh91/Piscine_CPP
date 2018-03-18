#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

#include <exception>
#include <iostream>

int    main ( void ) {

	Intern      idiotOne;
	Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 150);
	Bureaucrat  bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);

	// try {
	// 	ob.doBureaucracy("mutant pig termination", "Pigley");
	// }
	// catch (Some::SpecificException & e) {
	// 	/* specific known error happens, say something */
	// }
	// catch (std::exception & e) {
	// }
	
	try {
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (OfficeBlock::NoInternException & e) {
		std::cout << "You need an intern to run your office! " << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}