#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

#include <exception>
#include <iostream>


void tryToDoBureaucracy( OfficeBlock & o, std::string type, std::string target ) {
	try {
		o.doBureaucracy(type, target);
	}
	catch (OfficeBlock::NoInternException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "Suggestion: get an intern to do the shitty work!" << std::endl;
	}
	catch (OfficeBlock::NoSignerException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "Suggestion: get another bureaucrat to sign shitty papers!" << std::endl;
	}
	catch (OfficeBlock::NoExecutorException & e) {
		std::cout << e.what() << std::endl;
		std::cout << "Suggestion: get another bureaucrat to execute shitty forms!" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int    main ( void ) {

	Intern      idiotOne;
	Bureaucrat  clerk = Bureaucrat("Hermes Conrad", 150);
	Bureaucrat 	middle = Bureaucrat("Bobby Bobson", 123);
	Bureaucrat 	ceo = Bureaucrat("Randy P", 20);
	OfficeBlock ob;

	ob.setSigner(clerk);
	ob.setExecutor(middle);

	std::cout << "<< ======= ob ======= >>" << std::endl;
	tryToDoBureaucracy(ob, "presidential pardon", "Pigley");
	ob.setIntern(idiotOne);
	std::cout << "==================" << std::endl;
	tryToDoBureaucracy(ob, "robotomy request", "Trump");
	ob.setSigner(middle);
	ob.setExecutor(ceo);
	std::cout << "==================" << std::endl;
	tryToDoBureaucracy(ob, "shrubbery creation", "Home");
	

	std::cout << "<< ======= ob2 ====== >>" << std::endl;
	OfficeBlock ob2;
	ob2.setIntern(idiotOne);
	ob2.setExecutor(middle);
	tryToDoBureaucracy(ob2, "shrubbery creation", "Home");



	std::cout << "<< ======= ob3 ====== >>" << std::endl;
	OfficeBlock ob3;
	ob3.setIntern(idiotOne);
	ob3.setSigner(ceo);
	tryToDoBureaucracy(ob3, "shrubbery creation", "Home");


	std::cout << "<< ================== >>" << std::endl;
	return (0);
}