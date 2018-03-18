#include "Form.hpp"

#include <string>
#include <iostream>

Form::Form( void ) :
	_signed(false),
	_minSignGrade(150),
	_minExecuteGrade(150),
	_name("Default Form"),
	_target("Default Target") {
	
	return ;
};

Form::Form( std::string name, int minSignGrade, int minExecuteGrade, std::string target ) : 
	_signed(false), 
	_minSignGrade(minSignGrade),
	_minExecuteGrade(minExecuteGrade),
	_name(name),
	_target(target) {
	
	if ( this->_minSignGrade < 1 || this->_minExecuteGrade < 1 ) {
		throw (Form::GradeTooHighException());
	}
	else if ( this->_minSignGrade > 150 || this->_minExecuteGrade > 150 ) {
		throw (Form::GradeTooLowException());
	}
	
	return ;
};

Form::Form( Form const & form ) :
	_signed(form.isSigned()),
	_minSignGrade(form.getMinSignGrade()),
	_minExecuteGrade(form.getMinExecuteGrade()),
	_name(form.getName()),
	_target(form.getTarget()) {
	*this = form;
	return ;
};

Form::~Form( void ) {
	return ;
};

Form &    Form::operator=( Form const & rhs ) {
	this->_signed = rhs._signed;
	return (*this);
};

bool	Form::isSigned( void ) const {
	return (this->_signed);
};

int		Form::getMinSignGrade( void ) const {
	return (this->_minSignGrade);
};

int		Form::getMinExecuteGrade( void ) const {
	return (this->_minExecuteGrade);
};

std::string	Form::getName( void ) const  {
	return (this->_name);
}

std::string	Form::getTarget( void ) const  {
	return (this->_target);
}

void		Form::beSigned( Bureaucrat& bureaucrat ) {
	if ( this->isSigned() ) {
		throw( Form::AlreadySignedException() );
	}
	else if ( bureaucrat.getGrade() > this->getMinSignGrade() ) {
		throw( Form::GradeTooLowException() );
	}
	else {
		this->_signed = true;
	}
};

void 	Form::execute( Bureaucrat const & executor ) const {
	if ( !(this->isSigned()) ) {
		throw( Form::NotSignedException() );
	}
	else if ( executor.getGrade() > this->getMinExecuteGrade() ) {
		throw( Form::GradeTooLowException() );
	}
};

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

const char* Form::AlreadySignedException::what() const throw() {
	return "Form already signed";
};

const char* Form::NotSignedException::what() const throw() {
	return "Form not signed";
};

std::ostream& operator<<( std::ostream& os, const Form & form ) {
	os
		<< "(s.grade " << form.getMinSignGrade()
		<< ", ex.grade " << form.getMinExecuteGrade()
		<< ") "
		<< "targeted on " << form.getTarget();
    return os;
}