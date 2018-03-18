#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm( void ) :
	Form("Robotomy Request Form", 145, 137, "Default Target") {

	this->_initRand();
	return ;
};

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	Form("Robotomy Request Form", 145, 137, target) {
	
	this->_initRand();
	return ;
};

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	Form::execute( executor );
	
	std::cout << "* WHIRRR WHIRRR *" << std::endl;
	if (std::rand() % 2) {
		std::cout << this->getTarget() << " has been successfull robotomized !" << std::endl;
	} else {
		std::cout << "Robotomization failure ..." << std::endl;
	}
};

int RobotomyRequestForm::_randInit = 0;

void	RobotomyRequestForm::_initRand( void ) {
	if ( RobotomyRequestForm::_randInit == 0 ) {
		std::srand(std::time(nullptr));
		RobotomyRequestForm::_randInit = 1;
	}
};