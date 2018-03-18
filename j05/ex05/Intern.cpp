#include "Intern.hpp"

#include <iostream>

Intern::Intern( void ) {
	return ;
};

Intern::Intern( Intern const & intern ) {
	*this = intern;
	return ;
};

Intern::~Intern( void ) {
	return ;
};

Intern &    Intern::operator=( Intern const & rhs ) {
	( void )rhs;
	return (*this);
};

Form*	Intern::makeForm( std::string type, std::string target ) {
	Form* form;

	if ( type == "shrubbery creation" ) {
		form = new ShrubberyCreationForm(target);
	}
	else if ( type == "robotomy request" ) {
		form = new RobotomyRequestForm(target);
	}
	else if ( type == "presidential pardon" ) {
		form = new PresidentialPardonForm(target);
	}
	else {
		throw( Intern::FormTypeUnknownException() );
	}

	std::cout << "Intern creates a " << form->getName() << " " << *form << std::endl;
	return form;
};

const char* Intern::FormTypeUnknownException::what() const throw() {
	return "Form type unknown";
};