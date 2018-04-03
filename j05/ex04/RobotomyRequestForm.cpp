#include "RobotomyRequestForm.hpp"

/* ========== RobotomyRequestForm ========== */

RobotomyRequestForm::RobotomyRequestForm( void ) :
	Form("Robotomy Request Form", 72, 45, "Default Target") {
	this->_initRand();
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	Form("Robotomy Request Form", 72, 45, target) {
	this->_initRand();
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	Form::execute( executor );
	
	std::cout << "* WHIRRR WHIRRR *" << std::endl;
	if (std::rand() % 2) {
		std::cout << this->getTarget() << " has been successfull robotomized !" << std::endl;
	} else {
		std::cout << "Robotomization failure ..." << std::endl;
	}
}

bool RobotomyRequestForm::_randInit = false;

void	RobotomyRequestForm::_initRand( void ) {
	if ( RobotomyRequestForm::_randInit == false ) {
		std::srand(std::time(nullptr));
		RobotomyRequestForm::_randInit = true;
	}
}

RobotomyRequestForm &    RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
	(void)rhs;
	return (*this);
}