#include "PresidentialPardonForm.hpp"

/* ========== PresidentialPardonForm ========== */

PresidentialPardonForm::PresidentialPardonForm( void ) :
	Form("Presidential Pardon Form", 25, 5, "Default Target") {
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	Form("Presidential Pardon Form", 25, 5, target) {
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	Form::execute( executor );
	
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox " << std::endl;
}

PresidentialPardonForm &    PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
	(void)rhs;
	return (*this);
}