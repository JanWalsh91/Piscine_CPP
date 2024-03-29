#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_i = 0;
}

Fixed::Fixed( Fixed const & fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_i = fixed.getRawBits();
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_i = rhs._i;
	return (*this);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_i;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_i = raw;
}