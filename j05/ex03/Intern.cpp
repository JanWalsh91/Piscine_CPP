#include "Intern.hpp"

#include <iostream>

Intern::Intern( void ) {
	std::cout << "Anonymous intern created" << std::endl;
	return ;
};

Intern::Intern( Intern const & intern ) {
	std::cout << "Useless Intern copied" << std::endl;
	*this = intern;
	return ;
};

Intern::~Intern( void ) {
	std::cout << "Intern finished his internship" << std::endl;
	return ;
};

Intern &    Intern::operator=( Intern const & rhs ) {
	( void )rhs;
	return (*this);
};

Form*	Intern::makeForm( std::string type, std::string target ) {
	if ( type == "shrubbery creation" ) {
		return new ShrubberyCreationForm(target);
	}
	else if ( type == "robotomy request" ) {
		return new RobotomyRequestForm(target);
	}
	else if ( type == "presidential pardon" ) {
		return new PresidentialPardonForm(target);
	}
	else {
		throw( Intern::FormTypeUnknownException() );
	}
};

const char* Intern::FormTypeUnknownException::what() const throw() {
	return "Form type unknown";
};