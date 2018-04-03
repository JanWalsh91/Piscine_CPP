#include "PresidentialPardonForm.hpp"

/* ========== PresidentialPardonForm ========== */

PresidentialPardonForm::PresidentialPardonForm( void ) :
	Form("Presidential Pardon Form", 145, 137, "Default Target") {
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	Form("Presidential Pardon Form", 145, 137, target) {
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	Form::execute( executor );
	
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox " << std::endl;
}

PresidentialPardonForm &    PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
	(void)rhs;
	return (*this);
}