#include "Intern.hpp"

#include <iostream>

/* ========== Intern ========== */

Intern::Intern( void ) {}

Intern::Intern( Intern const & intern ) {
	*this = intern;
}

Intern::~Intern( void ) {}

Intern &    Intern::operator=( Intern const & rhs ) {
	( void )rhs;
	return (*this);
}

Form*	Intern::makeForm( std::string type, std::string target ) {
	std::string availableForms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	for ( int i = 0; i < 3; ++i ) {
		if ( type == availableForms[i] ) {
			Form * newForm = this->getForm[i]( target );
			std::cout << "Intern creates " << *newForm << std::endl;
			return newForm;
		}
	}

	throw( Intern::FormTypeUnknownException() );
}

Form *	Intern::makePresidentialPardonForm( std::string target ) {
	return new PresidentialPardonForm(target);
}
Form *	Intern::makeRobotomyRequestForm( std::string target ) {
	return new RobotomyRequestForm(target);
}
Form *	Intern::makeShrubberyCreationForm( std::string target ) {
	return new ShrubberyCreationForm(target);
}
const Intern::formGetter Intern::getForm[3] = {
	&(Intern::makeShrubberyCreationForm),
	&(Intern::makeRobotomyRequestForm),
	&(Intern::makePresidentialPardonForm)
};

/* ========== FormTypeUnknownException ========== */

Intern::FormTypeUnknownException::FormTypeUnknownException( void ) {}

Intern::FormTypeUnknownException::FormTypeUnknownException( Intern::FormTypeUnknownException const & e ) {
	*this = e;
}

Intern::FormTypeUnknownException::~FormTypeUnknownException( void ) throw() {}

Intern::FormTypeUnknownException &    Intern::FormTypeUnknownException::operator=( Intern::FormTypeUnknownException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* Intern::FormTypeUnknownException::what() const throw() {
	return "Form type unknown";
}