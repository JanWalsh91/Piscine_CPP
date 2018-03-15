#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed( int const i ) {
	std::cout << "Int constructor called" << std::endl;
	this->_i = i << this->_bit;
	return ;
};

Fixed::Fixed( float const i ) {
	std::cout << "Float constructor called" << std::endl;
	this->_i = i * (1 << this->_bit);
	return ;
};

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
};

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	this->_i = rhs._i;
	return (*this);
};

std::ostream &    operator<<( std::ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
};

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_i;
};

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_i = raw;
};

float	Fixed::toFloat( void ) const {
	return ( (float)this->_i / (1 << this->_bit) );
};

int		Fixed::toInt( void ) const {
	return (this->_i >> this->_bit);
};