#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryToSign( Bureaucrat& b, Form& f) {
	std::cout << "--- Try to Sign Form ---" << std::endl;
	try {
		b.signForm(f);
		std::cout << "\t" << f << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << "EXCEPTION NOT CAUGHT" << std::endl;
	}
	std::cout << std::endl;
}

int    main ( void ) {

	try {
		Form bad("Invalid Form", 130, -1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Form easy("Easy Form", 150, 100);
	Form medium("Medium Form", 50, 20);
	Form hard("Hard Form", 5, 1);
	
	Form defaultForm;
	Form defaultForm2(defaultForm);

	Form easy2(easy);
	Form medium2(medium);
	Form hard2(hard);

	std::cout << "\t" << easy << std::endl;
	std::cout << "\t" << easy2 << std::endl;
	std::cout << "\t" << medium << std::endl;
	std::cout << "\t" << hard << std::endl;
	std::cout << "\t" << defaultForm << std::endl;

	Bureaucrat clerk("Tom", 150);
	Bureaucrat mediumManagement("Jennifer", 70);
	Bureaucrat exec("Julie", 1);

	tryToSign(clerk, defaultForm);
	tryToSign(mediumManagement, defaultForm);
	tryToSign(clerk, medium);

	return (0);
}