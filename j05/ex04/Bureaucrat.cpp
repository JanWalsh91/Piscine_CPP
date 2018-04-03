#include "Bureaucrat.hpp"

/* ========== Bureaucrat ========== */

Bureaucrat::Bureaucrat( void ) : _grade(150), _name("Bureaucrat") {}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name) {
	this->_updateGrade( grade );
}

Bureaucrat::Bureaucrat( Bureaucrat const & bureaucrat ) :
	_grade(bureaucrat.getGrade()),
	_name(bureaucrat.getName()) {

	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat &    Bureaucrat::operator=( Bureaucrat const & rhs ) {
	this->_grade = rhs._grade;
	return (*this);
}

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
}

int	Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

const std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

void	Bureaucrat::incrementGrade( void ) {
	this->_updateGrade( this->_grade - 1 );
}

void	Bureaucrat::decrementGrade( void ) {
	this->_updateGrade( this->_grade + 1);
}

void	Bureaucrat::signForm( Form& form ) {
	form.beSigned( *this );
	std::cout << *this << " signs " << form << std::endl;
}

void	Bureaucrat::executeForm( Form& form ) {
	form.execute( *this );
	std::cout << *this << " executes " << form << std::endl;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat & bureaucrat ) {
	os << bureaucrat.getName() << " (Grade " << bureaucrat.getGrade() << ")";
    return os;
}

/* ========== GradeTooHighException ========== */

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {}

Bureaucrat::GradeTooHighException::GradeTooHighException( Bureaucrat::GradeTooHighException const & e ) {
	*this = e;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Bureaucrat::GradeTooHighException &    Bureaucrat::GradeTooHighException::operator=( Bureaucrat::GradeTooHighException const & rhs ) throw() {
	( void )rhs;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

/* ========== GradeTooLowException ========== */

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {}

Bureaucrat::GradeTooLowException::GradeTooLowException( Bureaucrat::GradeTooLowException const & e ) {
	*this = e;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Bureaucrat::GradeTooLowException &    Bureaucrat::GradeTooLowException::operator=( Bureaucrat::GradeTooLowException const & rhs ) {
	( void )rhs;
	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
