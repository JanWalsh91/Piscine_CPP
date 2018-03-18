#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <exception>

Bureaucrat::Bureaucrat( void ) : _grade(150), _name("Bureaucrat") {
	return ;
};

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name) {
	this->_updateGrade( grade );
	return ; 
};

Bureaucrat::Bureaucrat( Bureaucrat const & bureaucrat ) {
	*this = bureaucrat;
	return ;
};

Bureaucrat::~Bureaucrat( void ) {
	return ;
};

Bureaucrat &    Bureaucrat::operator=( Bureaucrat const & rhs ) {
	this->_grade = rhs._grade;
	return (*this);
};

void	Bureaucrat::_updateGrade( int grade ) {
	if ( grade < 1 ) {
		throw (Bureaucrat::GradeTooHighException());
	}
	else if ( grade > 150 ) {
		throw (Bureaucrat::GradeTooLowException());
	}
	else {
		this->_grade = grade;
	}
};

int	Bureaucrat::getGrade( void ) const {
	return (this->_grade);
};

const std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
};

void	Bureaucrat::incrementGrade( void ) {
	this->_updateGrade(--(this->_grade));
};

void	Bureaucrat::decrementGrade( void ) {
	this->_updateGrade(++(this->_grade));
};

void	Bureaucrat::signForm( Form& form ) {
	try {
		form.beSigned( *this );
		std::cout << *this << " signs " << form.getName() << " " << form << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout
			<< *this << " cannot sign " << form.getName() << " " << form
			<< " because " << e.what() << std::endl;
	}
};

void	Bureaucrat::executeForm( Form& form ) {
	try {
		form.execute( *this );
		std::cout << *this << " executes " << form.getName() << " " << form << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout
			<< *this << " cannot execute " << form.getName() << " " << form
			<< " because " << e.what() << std::endl;
	}
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat & bureaucrat ) {
	os
		<< "Bureaucrat" << bureaucrat.getName()
		<< "(Grade " << bureaucrat.getGrade() << ")";
    return os;
}