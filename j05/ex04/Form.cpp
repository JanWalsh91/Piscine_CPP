#include "Form.hpp"

/* ========== Form ========== */

Form::Form( void ) :
	_signed(false),
	_minSignGrade(150),
	_minExecuteGrade(150),
	_name("Default Form"),
	_target("Default Target") {
	
}

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
}

Form::Form( Form const & form ) :
	_signed(form.isSigned()),
	_minSignGrade(form.getMinSignGrade()),
	_minExecuteGrade(form.getMinExecuteGrade()),
	_name(form.getName()),
	_target(form.getTarget()) {
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

std::string	Form::getTarget( void ) const  {
	return (this->_target);
}

void		Form::beSigned( Bureaucrat& bureaucrat ) {
	if ( this->isSigned() ) {
		throw( Form::AlreadySignedException() );
	}
	else if ( bureaucrat.getGrade() > this->getMinSignGrade() ) {
		std::stringstream b;
		b << bureaucrat;
		std::stringstream f;
		f << *this;
		throw( Form::GradeTooLowException( b.str(), f.str(), "sign" ));
	}
	else {
		this->_signed = true;
	}
}

void 	Form::execute( Bureaucrat const & executor ) const {
	if ( !(this->isSigned()) ) {
		throw( Form::NotSignedException() );
	}
	else if ( executor.getGrade() > this->getMinExecuteGrade() ) {
		std::stringstream b;
		b << executor;
		std::stringstream f;
		f << *this;
		throw( Form::GradeTooLowException( b.str(), f.str(), "execute" ));
	}
}

std::ostream& operator<<( std::ostream& os, const Form & form ) {
	os
		<<	form.getName()
		<< " (s.grade " << form.getMinSignGrade()
		<< ", ex.grade " << form.getMinExecuteGrade()
		<< ") "
		<< "targeted on " << form.getTarget()
		<< (form.isSigned() ? " (Signed)" : " (Unsigned)");
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

Form::GradeTooLowException::GradeTooLowException( void ) : _bureaucrat(""), _form(""), _action("") {}

Form::GradeTooLowException::GradeTooLowException( std::string b, std::string f , std::string a ) : _bureaucrat( b ), _form( f ), _action( a ) {}

Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & e ) {
	*this = e;
}

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Form::GradeTooLowException &    Form::GradeTooLowException::operator=( Form::GradeTooLowException const & rhs ) {
	this->_bureaucrat = rhs._bureaucrat;
	this->_form = rhs._form;
	this->_action = rhs._action;
	return *this;
}

const char* Form::GradeTooLowException::what() const throw() {
	if ( this->_bureaucrat != "" && this->_form != "" && this->_action != "" ) {
		std::string s = this->_bureaucrat + " cannot " + this->_action + " " + this->_form + " because his grade is too low.";
		return s.c_str();
	}
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

/* ========== NotSignedException ========== */

Form::NotSignedException::NotSignedException( void ) {}

Form::NotSignedException::NotSignedException( Form::NotSignedException const & e ) {
	*this = e;
}

Form::NotSignedException::~NotSignedException( void ) throw() {}

Form::NotSignedException &    Form::NotSignedException::operator=( Form::NotSignedException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* Form::NotSignedException::what() const throw() {
	return "Form not signed";
}
