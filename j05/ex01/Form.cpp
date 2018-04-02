#include "Form.hpp"

/* ========== Form ========== */

Form::Form( void ) :
	_signed(false),
	_minSignGrade(150),
	_minExecuteGrade(150),
	_name("Default Form") {
	
	std::cout << this->getName() << " created." << std::endl;
}

Form::Form( std::string name, int minSignGrade, int minExecuteGrade ) : 
	_signed(false), 
	_minSignGrade(minSignGrade),
	_minExecuteGrade(minExecuteGrade),
	_name(name) {
	
	if ( this->_minSignGrade < 1 || this->_minExecuteGrade < 1 ) {
		throw (Form::GradeTooHighException());
	}
	else if ( this->_minSignGrade > 150 || this->_minExecuteGrade > 150 ) {
		throw (Form::GradeTooLowException());
	}
	
	std::cout << this->getName() << " created." << std::endl;
}

Form::Form( Form const & form ) :
	_signed(form.isSigned()),
	_minSignGrade(form.getMinSignGrade()),
	_minExecuteGrade(form.getMinExecuteGrade()),
	_name(form.getName()) {
	std::cout << this->getName() << " copied." << std::endl;
	*this = form;
}

Form::~Form( void ) {
	std::cout << this->getName() << " destroyed." << std::endl;
}

Form &    Form::operator=( Form const & rhs ) {
	this->_signed = rhs._signed;
	return (*this);
}

bool	Form::isSigned( void ) const {
	return (this->_signed);
}

int		Form::getMinSignGrade( void ) const {
	return (this->_minSignGrade);
}

int		Form::getMinExecuteGrade( void ) const {
	return (this->_minExecuteGrade);
}

std::string	Form::getName( void ) const  {
	return (this->_name);
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
}

std::ostream& operator<<( std::ostream& os, const Form & form ) {
	os
		<< "Form name: " << form.getName() << ",\t"
		<< "Signed status: " << (form.isSigned() ? "" : "not ") << "signed" << ",\t"
		<< "Min Grade to Sign:  " << form.getMinSignGrade() << ",\t"
		<< "Min Grade to Excecute:  " << form.getMinExecuteGrade();
    return os;
}

/* ========== GradeTooHighException ========== */

Form::GradeTooHighException::GradeTooHighException( void ) {}

Form::GradeTooHighException::GradeTooHighException( Form::GradeTooHighException const & e ) {
	*this = e;
}

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Form::GradeTooHighException &    Form::GradeTooHighException::operator=( Form::GradeTooHighException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

/* ========== GradeTooLowException ========== */

Form::GradeTooLowException::GradeTooLowException( void ) {}

Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & e ) {
	*this = e;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Form::GradeTooLowException &    Form::GradeTooLowException::operator=( Form::GradeTooLowException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

/* ========== AlreadySignedException ========== */

Form::AlreadySignedException::AlreadySignedException( void ) {}

Form::AlreadySignedException::AlreadySignedException( Form::AlreadySignedException const & e ) {
	*this = e;
}

Form::AlreadySignedException::~AlreadySignedException( void ) throw() {}

Form::AlreadySignedException &    Form::AlreadySignedException::operator=( Form::AlreadySignedException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Form already signed";
}