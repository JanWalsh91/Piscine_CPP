#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

void tryToSign( Bureaucrat& b, Form* f) {
	std::cout << "--- Try to Sign Form ---" << std::endl;
	try {
		b.signForm(*f);
		std::cout << "\t" << *f << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << "EXCEPTION NOT CAUGHT" << std::endl;
	}
	std::cout << std::endl;
}

void tryToExecute( Bureaucrat& b, Form* f) {
	std::cout << "--- Try to Execute Form ---" << std::endl;
	try {
		b.executeForm(*f);
		std::cout << *f << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << "EXCEPTION NOT CAUGHT" << std::endl;
	}
	std::cout << std::endl;
}

int    main ( void ) {

	Intern intern;

	try {
		Form* stupidForm = intern.makeForm("stupid form", "Dog");
		( void )stupidForm;
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}
	
	Form* shrub = intern.makeForm("shrubbery creation", "Home");
	Form* robo = intern.makeForm("robotomy request", "My Boss");
	Form* pardon = intern.makeForm("presidential pardon", "Xavier");

	Bureaucrat clerk("Tom", 150);
	Bureaucrat mediumManagement("Jennifer", 70);
	Bureaucrat exec("Julie", 1);

	tryToSign(clerk, shrub);
	tryToSign(mediumManagement, shrub);

	tryToExecute(clerk, shrub);
	tryToExecute(exec, shrub);
	tryToExecute(mediumManagement, shrub);

	tryToExecute(exec, robo);

	tryToSign(clerk, robo);
	tryToSign(exec, robo);

	tryToExecute(clerk, robo);
	tryToExecute(mediumManagement, robo);
	tryToExecute(exec, robo);
	tryToExecute(exec, robo);
	tryToExecute(exec, robo);

	tryToSign(clerk, pardon);
	tryToSign(exec, pardon);

	tryToExecute(clerk, pardon);
	tryToExecute(mediumManagement, pardon);
	tryToExecute(exec, pardon);
	
	delete shrub;
	delete robo;
	delete pardon;

	return (0);
}