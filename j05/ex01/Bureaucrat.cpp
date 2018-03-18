#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <exception>

Bureaucrat::Bureaucrat( void ) : _grade(150), _name("Bureaucrat") {
	std::cout << this->getName() << " created." << std::endl;
	return ;
};

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name) {
	this->_updateGrade( grade );
	std::cout << this->getName() << " created." << std::endl;
	return ; 
};

Bureaucrat::Bureaucrat( Bureaucrat const & bureaucrat ) {
	std::cout << this->getName() << " copied." << std::endl;
	*this = bureaucrat;
	return ;
};

Bureaucrat::~Bureaucrat( void ) {
	std::cout << *this << " destroyed." << std::endl;
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
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout
			<< this->getName() << " cannot sign " << form.getName()
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
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}