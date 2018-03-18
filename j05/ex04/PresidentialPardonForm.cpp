#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm( void ) :
	Form("Presidential Pardon Form", 145, 137, "Default Target") {

	return ;
};

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	Form("Presidential Pardon Form", 145, 137, target) {
	
	return ;
};

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	Form::execute( executor );
	
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox " << std::endl;

};