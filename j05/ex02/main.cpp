#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void tryToSign( Bureaucrat& b, Form& f) {
	std::cout << "\n--- Try to Sign Form ---" << std::endl;
	try {
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << "EXCEPTION NOT CAUGHT" << std::endl;
	}
}

void tryToExecute( Bureaucrat& b, Form& f) {
	std::cout << "\n--- Try to Execute Form ---" << std::endl;
	try {
		b.executeForm(f);
		std::cout << f << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << "EXCEPTION NOT CAUGHT" << std::endl;
	}
}

int    main ( void ) {

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robo("My Boss");
	PresidentialPardonForm pardon("Xavier");

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
	
	return (0);
}