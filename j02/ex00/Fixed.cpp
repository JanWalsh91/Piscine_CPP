#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_i = 0;
	return ;
};

Fixed::Fixed( Fixed const & fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_i = fixed.getRawBits();
	return ;
};

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
};

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	this->_i = rhs._i;
	return (*this);
};

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_i;
};

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_i = raw;
};